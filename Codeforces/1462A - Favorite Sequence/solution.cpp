/**
 * Problem: 1462A - Favorite Sequence
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1462/problem/A
 * Rating: 800
 * Tags: implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174058987
 * Submission Time: 2022-09-30 08:55:43 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 62 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1462/submission/174058987
 */

#include <iostream>
using namespace std;
#define int long long
const int ml = 1e6 + 2;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        int l = 1, p = n, i = 1;
        int b[n + 1];
        while(l <= p)
        {
            b[i] = a[l];
            b[++i] = a[p];
            p--;
            l++;
            i++;
        }
        for(i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }
}