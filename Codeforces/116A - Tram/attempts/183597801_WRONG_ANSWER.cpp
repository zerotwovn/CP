/**
 * Problem: 116A - Tram
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/116/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Wrong Answer
 * Submission ID: 183597801
 * Submission Time: 2022-12-02 12:56:33 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/116/submission/183597801
 */


#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a[n],b[n];
    for (int i = 0;i < n;i++) {
        cin >> a[i] >> b[i];
    }
    long long s = b[0]-a[0];
    for (int i = 1;i < n;i++) {
        s = max(s,s+b[i]-a[i]);
    }
    cout <<  s; 
    return 0;
}
