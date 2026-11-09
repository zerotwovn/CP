/**
 * Problem: 4C - Registration System
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/4/problem/C
 * Rating: 1300
 * Tags: data structures, hashing, implementation
 *
 * Verdict: Accepted
 * Submission ID: 182197234
 * Submission Time: 2022-11-23 03:25:58 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1370 ms
 * Memory: 900 KB
 * Link: https://codeforces.com/contest/4/submission/182197234
 */

#include <bits/stdc++.h>
using namespace std;
map<string, int> MAP;
int main() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (MAP.find(s) == MAP.end()) {
            MAP[s] = 1;
            cout << "OK" << endl;
        } else {
            cout << s << MAP[s] << endl;
            MAP[s]++;
        }
    }
    return 0;
}