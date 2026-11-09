/**
 * Problem: 158A - Next Round
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/158/problem/A
 * Rating: 800
 * Tags: *special, implementation
 *
 * Verdict: Wrong Answer
 * Submission ID: 182989014
 * Submission Time: 2022-11-28 09:52:02 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/158/submission/182989014
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n = 0, tg = 0;
    cin >> n >> tg;
    int dem = 0;
    long long a[n] = {};
    for (int i = 0 ;i < n;i++)
        cin >> a[i];
    for (int i = 0;i < n;i++)
        if(a[i] > tg)
            dem++;
    cout << dem;
    return 0;
}
