/**
 * Problem: 405A - Gravity Flip
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/405/problem/A
 * Rating: 900
 * Tags: greedy, implementation, sortings
 *
 * Verdict: Accepted
 * Submission ID: 185437774
 * Submission Time: 2022-12-16 09:36:32 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/405/submission/185437774
 */

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int a[n] = {};
    for(int i = 0;i < n;i++)
        cin >> a[i];
    sort(a,a+n);
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
}
