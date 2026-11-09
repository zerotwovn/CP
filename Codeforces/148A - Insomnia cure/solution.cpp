/**
 * Problem: 148A - Insomnia cure
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/148/problem/A
 * Rating: 800
 * Tags: constructive algorithms, implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 183970321
 * Submission Time: 2022-12-05 09:27:21 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/148/submission/183970321
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k,l,m,n,d;
    cin >> k >> l >> m >> n >>d;
    int dem = 0;
    for (int i = 1;i <=d;i++)
        if(i%k == 0 || i % l==0 || i%m==0 || i%n == 0)
            dem++;
    cout << dem;

    return 0;
}
