/**
 * Problem: 525A - Vitaliy and Pie
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/525/problem/A
 * Rating: 1100
 * Tags: greedy, hashing, strings
 *
 * Verdict: Accepted
 * Submission ID: 182415641
 * Submission Time: 2022-11-25 02:14:24 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/525/submission/182415641
 */

#include <iostream>
#include <cstring>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    int s[200];
    memset(s,0,sizeof(s));
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        char a,b;
        cin >> a >> b;
        s[a]++;
        if(s[b - 'A' + 'a'] == 0)
            ans++;
        else
            s[b - 'A' + 'a']--;
    }
    cout << ans;
}
