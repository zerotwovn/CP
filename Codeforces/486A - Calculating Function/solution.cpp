/**
 * Problem: 486A - Calculating Function
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/486/problem/A
 * Rating: 800
 * Tags: implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 183721529
 * Submission Time: 2022-12-03 11:56:05 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/486/submission/183721529
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n % 2 == 0)
        cout << n/2;
    else
        cout << -(n/2+1);
    return 0;
}
