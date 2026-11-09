/**
 * Problem: 1299C - Water Balance
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1299/problem/C
 * Rating: 2100
 * Tags: data structures, geometry, greedy
 *
 * Verdict: Accepted
 * Submission ID: 254781798
 * Submission Time: 2024-04-03 01:53:35 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 2687 ms
 * Memory: 23500 KB
 * Codeforces Link: https://codeforces.com/contest/1299/submission/254781798
 */

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, a[N], top;
struct node
{
	int len, sum;
}stk[N];
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	stk[++top].len = 1;
	stk[top].sum = a[1];
	for(int i = 2; i <= n; i++)
	{
		stk[++top].len = 1;
		stk[top].sum = a[i];
		while(top > 1)
		{
			double x = stk[top - 1].sum / 1.0 / stk[top - 1].len, y = stk[top].sum / 1.0 / stk[top].len;
			if(x >= y)
			{
				stk[top - 1].len += stk[top].len;
				stk[top - 1].sum += stk[top].sum;
				top--;
			}
			else
			{
				break;
			}
		}
	}
	for(int i = 1; i <= top; i++)
	{
		for(int j = 1; j <= stk[i].len; j++)
		{
			cout << fixed << setprecision(9) << stk[i].sum / 1.0 / stk[i].len << "\n"; 
		}
	}
	return 0;
}
