/**
 * Problem: 266A - Stones on the Table
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/266/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183574033
 * Submission Time: 2022-12-02 08:52:51 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/266/submission/183574033
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[n] = {};
    for (int i = 0;i < n;i++)
        cin >> s[i];
    int dem = 0;
    for (int i = 1;i < n;i++)
        if(s[i] == s[i-1]) 
            dem++;
    cout << dem;
    return 0;
}
