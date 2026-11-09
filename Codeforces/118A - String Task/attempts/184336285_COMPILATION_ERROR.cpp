/**
 * Problem: 118A - String Task
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/118/problem/A
 * Rating: 1000
 * Tags: implementation, strings
 *
 * Verdict: Compilation Error
 * Submission ID: 184336285
 * Submission Time: 2022-12-08 13:39:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/118/submission/184336285
 */

#include <bits/stdc++.h>
using namespace std; 
 
int main() {
    char s[101], s2[101];
    char s1[] = "aeiouy";
    cin >> s;
    int dai = s.size();
    for (int i = 0; i < dai; i++) {
        if (s[i] < 97)
            s[i] = s[i]+32;
    }
    int kt = 0;
 
    for (int i = 0; i < dai; i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i] == s1[j]) {
                kt = 1;
                break;
            }
 
        } 
        if (kt == 0) {
            cout << "." << s[i];
        }
        kt = 0;
    }
    cout << endl;
 
 
    return 0;
}