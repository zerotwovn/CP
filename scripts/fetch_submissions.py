#!/usr/bin/env python3
import os
import json
import time
import re
import urllib.request
import urllib.parse
import urllib.error
from concurrent.futures import ThreadPoolExecutor, as_completed

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CACHE_DIR = os.path.join(BASE_DIR, ".cache")
SUBMISSIONS_CACHE_DIR = os.path.join(CACHE_DIR, "submissions")
COOKIES_FILE = os.path.join(CACHE_DIR, "cookies.json")
HANDLE = "AZKHOI"

os.makedirs(SUBMISSIONS_CACHE_DIR, exist_ok=True)

def load_cookies():
    # Can load from file or environment variable CF_COOKIES
    if "CF_COOKIES" in os.environ:
        raw = os.environ["CF_COOKIES"]
        if raw.startswith("["):
            cookies_list = json.loads(raw)
            return "; ".join([f"{c['name']}={c['value']}" for c in cookies_list])
        return raw

    if os.path.exists(COOKIES_FILE):
        with open(COOKIES_FILE, "r") as f:
            data = json.load(f)
            if isinstance(data, list):
                return "; ".join([f"{c['name']}={c['value']}" for c in data])
            elif isinstance(data, dict):
                return "; ".join([f"{k}={v}" for k, v in data.items()])
    return ""

def get_csrf_token(cookie_header):
    url = f"https://codeforces.com/profile/{HANDLE}"
    req = urllib.request.Request(url, headers={
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
        "Cookie": cookie_header
    })
    with urllib.request.urlopen(req, timeout=15) as resp:
        html = resp.read().decode("utf-8", errors="ignore")
        match = re.search(r'csrf_token[\"\'\s:=]+([a-f0-9]{32})', html, re.I)
        if match:
            return match.group(1)
        match_meta = re.search(r'data-csrf=[\'\"]([a-f0-9]{32})[\'\"]', html, re.I)
        if match_meta:
            return match_meta.group(1)
    raise RuntimeError("Could not find CSRF token in profile page")

def fetch_submissions_list():
    url = f"https://codeforces.com/api/user.status?handle={HANDLE}&from=1&count=2000"
    req = urllib.request.Request(url, headers={"User-Agent": "Mozilla/5.0"})
    with urllib.request.urlopen(req, timeout=20) as resp:
        data = json.loads(resp.read().decode("utf-8"))
        if data.get("status") != "OK":
            raise RuntimeError(f"Codeforces API error: {data.get('comment')}")
        return data.get("result", [])

def fetch_submission_source(submission_id, csrf_token, cookie_header, max_retries=3):
    url = "https://codeforces.com/data/submitSource"
    data = urllib.parse.urlencode({
        "csrf_token": csrf_token,
        "submissionId": str(submission_id)
    }).encode("utf-8")

    for attempt in range(max_retries):
        try:
            req = urllib.request.Request(url, data=data, headers={
                "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
                "Cookie": cookie_header,
                "X-Csrf-Token": csrf_token,
                "Referer": f"https://codeforces.com/profile/{HANDLE}"
            })
            with urllib.request.urlopen(req, timeout=20) as resp:
                body = resp.read().decode("utf-8", errors="ignore")
                res = json.loads(body)
                source = res.get("source")
                if source is not None:
                    return source
        except Exception as e:
            if attempt == max_retries - 1:
                print(f"[WARN] Failed to fetch source for submission {submission_id}: {e}")
                return None
            time.sleep(2 * (attempt + 1))
    return None

def main():
    cookie_header = load_cookies()
    if not cookie_header:
        print("[ERROR] No cookies found. Please set CF_COOKIES or provide .cache/cookies.json")
        return

    print(f"[*] Fetching CSRF token for handle {HANDLE}...")
    csrf_token = get_csrf_token(cookie_header)
    print(f"[+] CSRF token: {csrf_token}")

    print(f"[*] Fetching submission history from Codeforces API...")
    submissions = fetch_submissions_list()
    print(f"[+] Found {len(submissions)} submissions.")

    # Save meta
    with open(os.path.join(CACHE_DIR, "all_submissions_meta.json"), "w") as f:
        json.dump(submissions, f, indent=2)

    # Check already cached
    to_fetch = []
    for s in submissions:
        sid = s["id"]
        cache_path = os.path.join(SUBMISSIONS_CACHE_DIR, f"{sid}.json")
        if os.path.exists(cache_path):
            try:
                with open(cache_path, "r") as f:
                    cached = json.load(f)
                    if cached.get("source"):
                        continue
            except Exception:
                pass
        to_fetch.append(s)

    print(f"[*] {len(submissions) - len(to_fetch)} submissions already cached. Need to fetch {len(to_fetch)} submissions.")

    if not to_fetch:
        print("[+] All submissions cached!")
        return

    total = len(to_fetch)
    print(f"[*] Starting gentle download of {total} submissions (1 request/sec)...")
    for i, sub in enumerate(to_fetch, 1):
        sid = sub["id"]
        prob = sub.get("problem", {})
        contest_id = sub.get("contestId", prob.get("contestId", "Unknown"))
        index = prob.get("index", "")
        pname = prob.get("name", "Unknown")
        source = fetch_submission_source(sid, csrf_token, cookie_header)
        if source:
            item = dict(sub)
            item["source"] = source
            cache_path = os.path.join(SUBMISSIONS_CACHE_DIR, f"{sid}.json")
            with open(cache_path, "w") as f:
                json.dump(item, f, indent=2)
            print(f"[{i}/{total}] ({i*100//total}%) Sub #{sid} ({contest_id}{index} - {pname}): {len(source)} bytes")
        else:
            print(f"[{i}/{total}] ({i*100//total}%) [WARN] Sub #{sid} failed to fetch source.")
        time.sleep(1.0)

    print("[+] All submissions processed!")

if __name__ == "__main__":
    main()
