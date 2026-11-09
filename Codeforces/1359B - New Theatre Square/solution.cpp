/**
 * Problem: 1359B - New Theatre Square
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1359/problem/B
 * Rating: 1000
 * Tags: brute force, dp, greedy, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174059190
 * Submission Time: 2022-09-30 08:57:49 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1359/submission/174059190
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                if(s[j] == '.' && s[j + 1] == '.')
                {
                    s[j] = '*';
                    s[j + 1] = '*';
                    ans += min(2 * x, y);
                    //cout << min(2 * x, y) << " ";
                }
                else
                    if(s[j] == '.')
                        ans += x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
