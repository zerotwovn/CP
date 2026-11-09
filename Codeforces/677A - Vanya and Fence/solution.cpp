/**
 * Problem: 677A - Vanya and Fence
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/677/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183695826
 * Submission Time: 2022-12-03 08:07:53 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/677/submission/183695826
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,h;
    cin >> n >> h;
    long long a[n] = {};
    long long sum = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i] > h)
            sum+=2;
        else
            sum+=1;
    }
    cout << sum;

    return 0;
}
