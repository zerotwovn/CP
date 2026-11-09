/**
 * Problem: 1030A - In Search of an Easy Problem
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1030/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183696475
 * Submission Time: 2022-12-03 08:13:23 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1030/submission/183696475
 */


#include <bits/stdc++.h>

using namespace std;
bool kiemtra (long long a[], long long n) {
    for (int i = 0;i < n;i++)
        if(a[i] == 1)
            return false;
        return true;
}
int main()
{
    long long n;
    cin >> n;
    long long a[n] = {};
    for (int i = 0;i < n;i++)
        cin >> a[i];
    if(kiemtra(a,n) == false)
        cout << "HARD";
    else
        cout << "EASY";

    return 0;
}
