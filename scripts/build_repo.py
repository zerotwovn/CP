#!/usr/bin/env python3
import os
import json
import re
import urllib.parse
from datetime import datetime, timezone
from collections import defaultdict

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CACHE_DIR = os.path.join(BASE_DIR, ".cache")
SUBMISSIONS_CACHE_DIR = os.path.join(CACHE_DIR, "submissions")
CODEFORCES_DIR = os.path.join(BASE_DIR, "Codeforces")
README_PATH = os.path.join(BASE_DIR, "README.md")
HANDLE = "AZKHOI"

def sanitize_filename(name):
    # Remove characters not safe in file/directory paths
    s = re.sub(r'[\\/*?:"<>|]', "", name)
    # Collapse consecutive spaces
    s = re.sub(r'\s+', " ", s).strip()
    return s

def get_extension(language):
    lang_lower = language.lower()
    if "c++" in lang_lower:
        return ".cpp"
    elif "gnu c" in lang_lower or language == "C":
        return ".c"
    elif "python" in lang_lower or "pypy" in lang_lower:
        return ".py"
    elif "java" in lang_lower:
        return ".java"
    elif "kotlin" in lang_lower:
        return ".kt"
    elif "rust" in lang_lower:
        return ".rs"
    return ".txt"

def format_verdict(verdict):
    if verdict == "OK":
        return "Accepted"
    elif verdict == "WRONG_ANSWER":
        return "Wrong Answer"
    elif verdict == "TIME_LIMIT_EXCEEDED":
        return "Time Limit Exceeded"
    elif verdict == "MEMORY_LIMIT_EXCEEDED":
        return "Memory Limit Exceeded"
    elif verdict == "COMPILATION_ERROR":
        return "Compilation Error"
    elif verdict == "RUNTIME_ERROR":
        return "Runtime Error"
    elif verdict == "CHALLENGED":
        return "Hacked"
    elif verdict == "PARTIAL":
        return "Partial"
    return verdict or "Unknown"

def verdict_badge_color(verdict):
    if verdict == "OK":
        return "brightgreen"
    elif verdict in ["WRONG_ANSWER", "RUNTIME_ERROR", "CHALLENGED"]:
        return "red"
    elif verdict in ["TIME_LIMIT_EXCEEDED", "MEMORY_LIMIT_EXCEEDED"]:
        return "yellow"
    elif verdict == "COMPILATION_ERROR":
        return "orange"
    return "lightgrey"

def rating_badge_color(rating):
    if not rating:
        return "lightgrey"
    if rating < 1200:
        return "gray"
    elif rating < 1400:
        return "green"
    elif rating < 1600:
        return "cyan"
    elif rating < 1900:
        return "blue"
    elif rating < 2100:
        return "purple"
    elif rating < 2400:
        return "orange"
    return "red"

def make_source_header(sub, ext):
    prob = sub.get("problem", {})
    cid = sub.get("contestId", prob.get("contestId", "Unknown"))
    idx = prob.get("index", "")
    pname = prob.get("name", "Unknown")
    verdict_str = format_verdict(sub.get("verdict"))
    sid = sub.get("id")
    lang = sub.get("programmingLanguage", "")
    ts = sub.get("creationTimeSeconds", 0)
    dt_str = datetime.fromtimestamp(ts, timezone.utc).strftime("%Y-%m-%d %H:%M:%S UTC") if ts else "Unknown"
    time_ms = sub.get("timeConsumedMillis", 0)
    mem_kb = sub.get("memoryConsumedBytes", 0) // 1024
    rating = prob.get("rating", "Unrated")
    tags = ", ".join(prob.get("tags", []))
    problem_url = f"https://codeforces.com/contest/{cid}/problem/{idx}" if cid != "Unknown" else "https://codeforces.com"
    sub_url = f"https://codeforces.com/contest/{cid}/submission/{sid}" if cid != "Unknown" else ""

    if ext in [".cpp", ".c", ".java", ".kt", ".rs"]:
        header = f"""/**
 * Problem: {cid}{idx} - {pname}
 * Contest: Codeforces
 * URL: {problem_url}
 * Rating: {rating}
 * Tags: {tags}
 *
 * Verdict: {verdict_str}
 * Submission ID: {sid}
 * Submission Time: {dt_str}
 * Language: {lang}
 * Time: {time_ms} ms
 * Memory: {mem_kb} KB
 * Link: {sub_url}
 */

"""
    elif ext == ".py":
        header = f"""\"\"\"
Problem: {cid}{idx} - {pname}
Contest: Codeforces
URL: {problem_url}
Rating: {rating}
Tags: {tags}

Verdict: {verdict_str}
Submission ID: {sid}
Submission Time: {dt_str}
Language: {lang}
Time: {time_ms} ms
Memory: {mem_kb} KB
Link: {sub_url}
\"\"\"

"""
    else:
        header = ""
    return header

def main():
    if not os.path.exists(SUBMISSIONS_CACHE_DIR):
        print(f"[ERROR] Cache directory {SUBMISSIONS_CACHE_DIR} does not exist.")
        return

    cached_files = [f for f in os.listdir(SUBMISSIONS_CACHE_DIR) if f.endswith(".json")]
    if not cached_files:
        print("[ERROR] No cached submission files found.")
        return

    print(f"[*] Processing {len(cached_files)} cached submissions...")

    all_submissions = []
    for fname in cached_files:
        with open(os.path.join(SUBMISSIONS_CACHE_DIR, fname), "r") as f:
            try:
                sub = json.load(f)
                all_submissions.append(sub)
            except Exception as e:
                print(f"[WARN] Failed to read {fname}: {e}")

    # Group by problem: (contestId, index)
    grouped = defaultdict(list)
    for sub in all_submissions:
        prob = sub.get("problem", {})
        cid = sub.get("contestId", prob.get("contestId", 0))
        idx = prob.get("index", "")
        grouped[(cid, idx)].append(sub)

    os.makedirs(CODEFORCES_DIR, exist_ok=True)

    # Clean existing generated problem folders in Codeforces/ if any
    # (keeps git history clean and accurately mirrors state)
    for item in os.listdir(CODEFORCES_DIR):
        p = os.path.join(CODEFORCES_DIR, item)
        if os.path.isdir(p):
            import shutil
            shutil.rmtree(p)

    rating_counts = defaultdict(int)
    tag_counts = defaultdict(int)
    total_solved = 0
    total_submissions = len(all_submissions)
    problem_records = []

    for (cid, idx), subs in grouped.items():
        # Sort submissions chronologically (oldest to newest)
        subs.sort(key=lambda s: s.get("creationTimeSeconds", 0))
        
        prob = subs[0].get("problem", {})
        pname = prob.get("name", f"Problem {idx}")
        rating = prob.get("rating")
        tags = prob.get("tags", [])
        
        # Check if solved
        ac_subs = [s for s in subs if s.get("verdict") == "OK"]
        is_solved = len(ac_subs) > 0
        if is_solved:
            total_solved += 1
            if rating:
                rating_counts[rating] += 1
            for t in tags:
                tag_counts[t] += 1

        # Primary solution: pick the best AC submission (or latest attempt if no AC)
        if ac_subs:
            # Pick AC submission with least time / latest
            primary_sub = min(ac_subs, key=lambda s: (s.get("timeConsumedMillis", 999999), -s.get("creationTimeSeconds", 0)))
        else:
            primary_sub = subs[-1]

        safe_pname = sanitize_filename(pname)
        folder_name = f"{cid}{idx} - {safe_pname}"
        folder_path = os.path.join(CODEFORCES_DIR, folder_name)
        os.makedirs(folder_path, exist_ok=True)

        primary_ext = get_extension(primary_sub.get("programmingLanguage", ""))
        raw_source = primary_sub.get("source")
        if not raw_source:
            raw_source = (
                "// Source code pending synchronization.\n"
                f"// View on Codeforces: https://codeforces.com/contest/{cid}/submission/{primary_sub.get('id')}\n"
                "// Run 'python3 scripts/sync_codeforces.py' to update locally or trigger GitHub Actions.\n"
            )
        primary_file_content = make_source_header(primary_sub, primary_ext) + raw_source
        primary_file_path = os.path.join(folder_path, f"solution{primary_ext}")
        with open(primary_file_path, "w", encoding="utf-8") as f:
            f.write(primary_file_content)

        # If multiple attempts exist, save all attempts in attempts/ directory
        if len(subs) > 1:
            attempts_dir = os.path.join(folder_path, "attempts")
            os.makedirs(attempts_dir, exist_ok=True)
            for sub in subs:
                sid = sub.get("id")
                verdict = sub.get("verdict", "UNKNOWN")
                sub_ext = get_extension(sub.get("programmingLanguage", ""))
                sub_source = sub.get("source")
                if not sub_source:
                    sub_source = (
                        "// Source code pending synchronization.\n"
                        f"// View on Codeforces: https://codeforces.com/contest/{cid}/submission/{sid}\n"
                    )
                sub_content = make_source_header(sub, sub_ext) + sub_source
                sub_file_name = f"{sid}_{verdict}{sub_ext}"
                with open(os.path.join(attempts_dir, sub_file_name), "w", encoding="utf-8") as f:
                    f.write(sub_content)

        # Generate Problem README.md
        problem_url = f"https://codeforces.com/contest/{cid}/problem/{idx}"
        rating_badge = f"![Rating](https://img.shields.io/badge/Rating-{rating if rating else 'Unrated'}-{rating_badge_color(rating)}.svg)"
        verdict_badge = f"![Verdict](https://img.shields.io/badge/Verdict-{format_verdict(primary_sub.get('verdict'))}-{verdict_badge_color(primary_sub.get('verdict'))}.svg)"

        problem_readme = f"""# [{cid}{idx} - {pname}]({problem_url})

{verdict_badge} {rating_badge}

## Problem Information
- **Contest:** [{cid}](https://codeforces.com/contest/{cid})
- **Problem Index:** {idx}
- **Rating:** {rating if rating else 'Unrated'}
- **Tags:** {', '.join([f'`{t}`' for t in tags]) if tags else 'None'}
- **Primary Solution:** [`solution{primary_ext}`](solution{primary_ext})

## Submissions History

| # | Submission ID | Verdict | Language | Time | Memory | Submitted At | Link |
|---|---------------|---------|----------|------|--------|--------------|------|
"""
        for i, s in enumerate(reversed(subs), 1):
            sid = s.get("id")
            s_verdict = format_verdict(s.get("verdict"))
            s_lang = s.get("programmingLanguage", "")
            s_time = f"{s.get('timeConsumedMillis', 0)} ms"
            s_mem = f"{s.get('memoryConsumedBytes', 0) // 1024} KB"
            s_ts = s.get("creationTimeSeconds", 0)
            s_dt = datetime.fromtimestamp(s_ts, timezone.utc).strftime("%Y-%m-%d %H:%M") if s_ts else "-"
            s_link = f"[#{sid}](https://codeforces.com/contest/{cid}/submission/{sid})"
            problem_readme += f"| {i} | {sid} | {s_verdict} | {s_lang} | {s_time} | {s_mem} | {s_dt} | {s_link} |\n"

        with open(os.path.join(folder_path, "README.md"), "w", encoding="utf-8") as f:
            f.write(problem_readme)

        problem_records.append({
            "contestId": cid,
            "index": idx,
            "name": pname,
            "rating": rating or 0,
            "tags": tags,
            "folder_name": folder_name,
            "primary_ext": primary_ext,
            "is_solved": is_solved,
            "attempts_count": len(subs),
            "primary_verdict": primary_sub.get("verdict"),
            "latest_sub_ts": subs[-1].get("creationTimeSeconds", 0)
        })

    # Sort problem records: solved first, then by contest ID numeric, then index
    def sort_key(rec):
        try:
            cid_int = int(rec["contestId"])
        except ValueError:
            cid_int = 999999
        return (not rec["is_solved"], cid_int, rec["index"])

    problem_records.sort(key=sort_key)

    # Generate Root README.md
    print("[*] Generating root repository README.md...")
    readme_content = f"""# Competitive Programming (CP) 🚀

[![Codeforces Profile](https://img.shields.io/badge/Codeforces-{HANDLE}-1f8acb?style=for-the-badge&logo=codeforces&logoColor=white)](https://codeforces.com/profile/{HANDLE})
[![Solved Problems](https://img.shields.io/badge/Solved-{total_solved}-brightgreen?style=for-the-badge)](https://codeforces.com/profile/{HANDLE})
[![Total Submissions](https://img.shields.io/badge/Submissions-{total_submissions}-blue?style=for-the-badge)](https://codeforces.com/profile/{HANDLE})
[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%7C%20C11-orange?style=for-the-badge&logo=c%2B%2B)](templates/template.cpp)
[![Auto Sync](https://img.shields.io/badge/Auto--Sync-GitHub%20Actions-brightgreen?style=for-the-badge&logo=githubactions&logoColor=white)](.github/workflows/codeforces_sync.yml)

Automated Competitive Programming archive and tracker for **[{HANDLE}](https://codeforces.com/profile/{HANDLE})** on Codeforces.
Contains solutions, problem statements, submission history, and templates.

---

## 📊 Summary Statistics

| Metric | Value |
|:---|:---|
| 👤 **Handle** | [{HANDLE}](https://codeforces.com/profile/{HANDLE}) |
| 🎯 **Total Problems Solved** | **{total_solved}** |
| 📝 **Total Submissions** | **{total_submissions}** |
| 📈 **Accepted Ratio** | **{(total_solved / len(grouped) * 100):.1f}%** ({total_solved}/{len(grouped)} unique problems) |
| 💻 **Primary Languages** | C++17, GNU C11 |
| 🔄 **Last Synced** | {datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M:%S UTC')} |

---

## 📈 Rating Distribution

| Rating | Count | Bar |
|:---:|:---:|:---|
"""
    for r in sorted(rating_counts.keys()):
        cnt = rating_counts[r]
        bar = "█" * min(30, (cnt * 30 // max(rating_counts.values())))
        readme_content += f"| **{r}** | {cnt} | `{bar}` |\n"

    readme_content += """
---

## 🏷️ Top Tags Distribution

| Tag | Count |
|:---|:---:|
"""
    sorted_tags = sorted(tag_counts.items(), key=lambda x: x[1], reverse=True)
    for tag, cnt in sorted_tags[:15]:
        readme_content += f"| `{tag}` | {cnt} |\n"

    readme_content += """
---

## 📁 Repository Structure

```
CP/
├── Codeforces/                    # Codeforces problem solutions & metadata
│   ├── <ContestId><Index> - <Name>/
│   │   ├── solution.cpp           # Best / Accepted solution
│   │   ├── README.md              # Problem info, tags, links & submission history
│   │   └── attempts/              # Additional submissions/attempts (if any)
├── templates/                     # CP Starter templates & fast I/O
│   └── template.cpp               # C++ competitive programming template
├── scripts/                       # Automation and synchronization scripts
│   ├── fetch_submissions.py       # Codeforces downloader with session handling
│   ├── build_repo.py              # Generator for folders, READMEs and stats
│   └── sync_codeforces.py         # Full sync pipeline (API + download + build)
└── .github/workflows/             # GitHub Actions automated sync workflow
    └── codeforces_sync.yml
```

---

## 📚 Solved Problems ({total_solved})

| # | Problem | Rating | Tags | Solution | Attempts |
|:---:|:---|:---:|:---|:---:|:---:|
"""
    solved_idx = 1
    for rec in problem_records:
        if not rec["is_solved"]:
            continue
        cid = rec["contestId"]
        idx = rec["index"]
        pname = rec["name"]
        rating_str = str(rec["rating"]) if rec["rating"] > 0 else "-"
        tags_str = ", ".join([f"`{t}`" for t in rec["tags"][:3]])
        folder_link = f"[📁 {cid}{idx} - {pname}](Codeforces/{urllib.parse.quote(rec['folder_name'])})"
        sol_link = f"[`solution{rec['primary_ext']}`](Codeforces/{urllib.parse.quote(rec['folder_name'])}/solution{rec['primary_ext']})"
        attempts_badge = f"{rec['attempts_count']}"

        readme_content += f"| {solved_idx} | {folder_link} | {rating_str} | {tags_str} | {sol_link} | {attempts_badge} |\n"
        solved_idx += 1

    # Non-solved (attempted) section if any
    attempted_records = [r for r in problem_records if not r["is_solved"]]
    if attempted_records:
        readme_content += f"""
---

## ⏳ In Progress / Attempted ({len(attempted_records)})

| # | Problem | Rating | Tags | Attempts |
|:---:|:---|:---:|:---|:---:|
"""
        for i, rec in enumerate(attempted_records, 1):
            cid = rec["contestId"]
            idx = rec["index"]
            pname = rec["name"]
            rating_str = str(rec["rating"]) if rec["rating"] > 0 else "-"
            tags_str = ", ".join([f"`{t}`" for t in rec["tags"][:3]])
            folder_link = f"[📁 {cid}{idx} - {pname}](Codeforces/{urllib.parse.quote(rec['folder_name'])})"
            readme_content += f"| {i} | {folder_link} | {rating_str} | {tags_str} | {rec['attempts_count']} |\n"

    readme_content += """
---

## ⚡ Useful Extensions & Live Plugins

To sync future submissions automatically in real-time or enhance your CP workflow:

1. **[CFPusher (Chrome Extension)](https://chromewebstore.google.com/search/cfpusher)**
   - Automatically detects Accepted Codeforces submissions and commits them to this `CP` repository.
   - Configure with your GitHub Personal Access Token (PAT) with `repo` permission and point to `zerotwovn/CP`.

2. **[Competitive Companion](https://github.com/jmerle/competitive-companion)**
   - Chrome / Firefox extension that parses problem test cases with 1-click and sends them to VS Code / CPH.

3. **[CPH (Competitive Programming Helper)](https://marketplace.visualstudio.com/items?itemName=DivyanshuAgrawal.competitive-programming-helper)**
   - VS Code extension for running test cases automatically.

4. **Automated GitHub Actions Sync**
   - This repository is equipped with a GitHub Action (`.github/workflows/codeforces_sync.yml`) that can run automatically on schedule or with one click (`workflow_dispatch`).
   - To enable the workflow to fetch new source code, add your Codeforces cookies JSON into GitHub Repository Secrets as `CF_COOKIES`.

---

*Generated with ❤️ for [AZKHOI](https://codeforces.com/profile/AZKHOI)*
"""

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(readme_content)

    print(f"[+] Successfully built repository! Solved: {total_solved}/{len(grouped)}.")

if __name__ == "__main__":
    main()
