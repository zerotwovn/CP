/**
 * Problem: 486A - Calculating Function
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/486/problem/A
 * Rating: 800
 * Tags: implementation, math
 *
 * Verdict: Time Limit Exceeded
 * Submission ID: 183721102
 * Submission Time: 2022-12-03 11:51:48 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1000 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/486/submission/183721102
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long s = 0;
    for (int i = 1;i <= n;i++)
        if(i % 2 == 0)
            s+=i;
        else
            s-=i;
    cout << s;
    return 0;
}
