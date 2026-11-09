/**
 * Problem: 136A - Presents
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/136/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183699590
 * Submission Time: 2022-12-03 08:40:24 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/136/submission/183699590
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    int a[n+1] = {};
    for(int i = 1;i <= n;i++) {
        cin >> x;
        a[x] = i;
    }
    for (int i = 1;i <= n;i++)
        cout << a[i] << " ";
    return 0;
}
