/**
 * Problem: 1133C - Balanced Team
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1133/problem/C
 * Rating: 1200
 * Tags: sortings, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174063210
 * Submission Time: 2022-09-30 09:40:35 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 78 ms
 * Memory: 1600 KB
 * Link: https://codeforces.com/contest/1133/submission/174063210
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
signed main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0, j = 1;
    for(int i = 1; i <= n; i++)
    {
        while(j <= n && a[j] - a[i] <= 5)
        {
            j++;
            ans = max(ans,j - i);
        }
    }
    cout << ans;
}