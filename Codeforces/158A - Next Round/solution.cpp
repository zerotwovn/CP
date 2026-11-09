/**
 * Problem: 158A - Next Round
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/158/problem/A
 * Rating: 800
 * Tags: *special, implementation
 *
 * Verdict: Accepted
 * Submission ID: 182989348
 * Submission Time: 2022-11-28 09:56:14 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/158/submission/182989348
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
    long long tmp = a[tg-1];
    for (int i = 0;i < n;i++)
        if(a[i] >= tmp && a[i] > 0)
            dem++;
    cout << dem;
    return 0;
}
