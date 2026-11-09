/**
 * Problem: 1689A - Lex String
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1689/problem/A
 * Rating: 800
 * Tags: brute force, greedy, implementation, sortings, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 173764844
 * Submission Time: 2022-09-28 01:12:44 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 100 KB
 * Link: https://codeforces.com/contest/1689/submission/173764844
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int ml = 1e6 + 2;
signed main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        string a,b;
        cin >> a >> b;
        string c = "";
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int first = 0, last = 0;
	    for (int i = 0, j = 0; i < n && j < m;)
        {
		    if (a[i] < b[j])
            {
			    if (last == 1 && first == k)
                {
				    c.push_back(b[j++]);
				    last = 2;
				    first = 1;
			    }
                else
                {
				    c.push_back(a[i++]);
				    if (last == 1) first++; else first = 1;
				    last = 1;
			    }
		    }
            else
			if (last == 2 && first == k)
            {
				c.push_back(a[i++]);
				last = 1;
				first = 1;
			}
            else
            {
				c.push_back(b[j++]);
				if (last == 2) first++; else first = 1;
				last = 2;
		    }
	    }
	cout << c << "\n";
    }
}