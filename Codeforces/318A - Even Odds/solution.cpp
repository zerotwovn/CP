/**
 * Problem: 318A - Even Odds
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/318/problem/A
 * Rating: 900
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 185435981
 * Submission Time: 2022-12-16 09:17:21 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/318/submission/185435981
 */

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n, k,tmp;
    cin >> n >> k;
 
    if( k <= (n+1)/2)
    {
        tmp = k*2 - 1;
    }
    else
    {
        tmp = (k - (n+1)/2)*2;
    }
    cout << tmp << endl;
}
