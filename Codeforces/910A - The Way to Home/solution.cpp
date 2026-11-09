/**
 * Problem: 910A - The Way to Home
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/910/problem/A
 * Rating: 800
 * Tags: dfs and similar, dp, greedy, implementation
 *
 * Verdict: Accepted
 * Submission ID: 177939020
 * Submission Time: 2022-10-26 02:22:41 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/910/submission/177939020
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,d,count=0;
	cin >> n >> d;
	string s;
	cin >> s;
//	cout << s.length() ;
	for (int i=0;i<=s.length()-1;i++)
	{
//		cout << i <<" ";
		if (s[i]=='1' && i!=s.length()-1)
		{
			bool kt=false;
			for (int j=i+d;j>=i+1;j--)
	    	{
			if (s[j]=='1')
			{
				count++;
				i=j-1;
				kt=true;
				break;
			}

	    	}
			if (kt==false)
			{
				cout << -1 ;
				count=0;
				break;
			}
		}
	}
	if (count > 0) cout << count ;
}