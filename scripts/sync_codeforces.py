#!/usr/bin/env python3
import os
import sys
import subprocess

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def run_step(description, script_name):
    print(f"\n==========================================")
    print(f"[*] {description}...")
    print(f"==========================================")
    script_path = os.path.join(SCRIPT_DIR, script_name)
    res = subprocess.run([sys.executable, script_path])
    if res.returncode != 0:
        print(f"[ERROR] Step {script_name} failed with exit code {res.returncode}")
        return False
    return True

def main():
    if not run_step("Fetching Codeforces Submissions", "fetch_submissions.py"):
        sys.exit(1)
    if not run_step("Building Repository and README Dashboard", "build_repo.py"):
        sys.exit(1)
    print("\n[+] Sync process completed successfully!")

if __name__ == "__main__":
    main()
