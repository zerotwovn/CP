/**
 * Problem: 1343C - Alternating Subsequence
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1343/problem/C
 * Rating: 1200
 * Tags: dp, greedy, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174059140
 * Submission Time: 2022-09-30 08:57:15 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 77 ms
 * Memory: 1600 KB
 * Codeforces Link: https://codeforces.com/contest/1343/submission/174059140
 */

#include <iostream>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        bool check = (a[1] > 0) ? true : false;
        int ans = 0, m = a[1];
        for (int i = 2; i <= n; i++)
        {
            if (!check && a[i] < 0)
                m = max(m, a[i]);
            else 
            if (!check && a[i] > 0)
            {
                ans += m;
                m = a[i];
                check = true;
            }
            else 
            if (check && a[i] > 0)
                m = max(m, a[i]);
            else 
            if (check && a[i] < 0)
            {
                ans += m;
                m = a[i];
                check = false;
            }
        }
        cout << ans + m << "\n";
    }
    return 0;
}
