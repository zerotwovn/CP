/**
 * Problem: 344A - Magnets
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/344/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183720866
 * Submission Time: 2022-12-03 11:49:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 186 ms
 * Memory: 800 KB
 * Link: https://codeforces.com/contest/344/submission/183720866
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n] = {};
    for (int i = 0;i < n;i++)
        cin >> a[i];
    int dem = 0;
    for (int i = 1;i < n;i++)
        if(a[i] != a[i-1])
            dem++;
    cout << dem+1;
    return 0;
}
