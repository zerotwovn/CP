/**
 * Problem: 200B - Drinks
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/200/problem/B
 * Rating: 800
 * Tags: implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 183722452
 * Submission Time: 2022-12-03 12:05:32 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/200/submission/183722452
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n] = {};
    float s = 0;
    for (int i = 0;i < n;i++)
    {cin >> a[i];s+=a[i];}
    float avg = 0;
    avg = s/(n*100.0)*100.0;
    cout << avg;
    return 0;
}
