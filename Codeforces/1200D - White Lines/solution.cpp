/**
 * Problem: 1200D - White Lines
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1200/problem/D
 * Rating: 1900
 * Tags: brute force, data structures, dp, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 196474285
 * Submission Time: 2023-03-08 07:29:17 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1387 ms
 * Memory: 19800 KB
 * Codeforces Link: https://codeforces.com/contest/1200/submission/196474285
 */

#include<bits/stdc++.h>
using namespace std;
const int N=2010;
char ch[N][N];
int a[N][N];
int main()
{
	int n,k;
	cin>>n>>k;
	int l,r;
	for(int i=1;i<=n;i++)
	{
		for(int j=1 ;j<=n;j++)
		{
			cin>>ch[i][j];
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		l=r=-1;
		for(int j=1;j<=n;j++)
		{
			if(ch[i][j]=='B')
			{
				if(l<0)
					l=j;
				r=j;
			}
		}
		if(l<0)
			sum++;
		else if(r-l+1<=k)
		{
			for(int i1=max(1,i-k+1);i1<=i;i1++)
			{
				for(int j1=max(1,r-k+1);j1<=l;j1++)
				{
					a[i1][j1]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		l=r=-1;
		for(int j=1;j<=n;j++)
		{
			if(ch[j][i]=='B')
			{
				if(l<0)
				l=j;
				r=j;
			}
		}
		if(l<0)
			sum++;
		else if(r-l+1<=k)
		{
			for(int i1=max(1,i-k+1);i1<=i;i1++)
			{
				for(int j1=max(1,r-k+1);j1<=l;j1++)
				{
					a[j1][i1]++;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,a[i][j]);
		}
	}
	cout<<ans+sum<<endl;
}
