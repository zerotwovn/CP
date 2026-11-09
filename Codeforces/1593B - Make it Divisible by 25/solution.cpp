/**
 * Problem: 1593B - Make it Divisible by 25
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1593/problem/B
 * Rating: 900
 * Tags: dfs and similar, dp, greedy, math
 *
 * Verdict: Accepted
 * Submission ID: 177937883
 * Submission Time: 2022-10-26 01:56:00 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1593/submission/177937883
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll count,t;
	cin >> t;
	ll temp=t;
	while (t--)
	{	
	  
//	bool kt=false;
		count=0;
	
		string s;
		cin >> s;
		int n=s.length()-1;
		int a[n+1];
		for (int i=0;i<=n;i++)
		{
			a[i]=20;
		    if (s[i]=='5')
			{
			for (int j=i-1;j>=0;j--)
			{
				if (s[j]=='2' || s[j]=='7') 
				{
					a[i]=min(a[i],(i-j-1)+(n-i));
					break;
				}
			}
			}
			else if (s[i]=='0')
			{
				for (int j=i-1;j>=0;j--)
			{
				if (s[j]=='5' || s[j]=='0') 
				{
					a[i]=min(a[i],(i-j-1)+(n-i));
					break;
				}
			}	
			}
		
		}
//		for (int i=0;i<=n;i++) cout << a[i] <<" " ;
		cout << *min_element(a,a+n+1) << endl;
	}
}
