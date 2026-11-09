/**
 * Problem: 467A - George and Accommodation
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/467/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183696832
 * Submission Time: 2022-12-03 08:16:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/467/submission/183696832
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n],b[n];
    for (int i = 0; i <n;i++)
        cin >> a[i] >> b[i];
    int dem = 0;
    for (int i = 0;i < n;i++)
        if(b[i] - a[i] >= 2)
            dem++;
    cout << dem;
    return 0;
}
