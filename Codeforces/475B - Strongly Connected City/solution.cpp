/**
 * Problem: 475B - Strongly Connected City
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/475/problem/B
 * Rating: 1400
 * Tags: brute force, dfs and similar, graphs, implementation
 *
 * Verdict: Accepted
 * Submission ID: 177938281
 * Submission Time: 2022-10-26 02:04:51 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/475/submission/177938281
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int long long uill;
int main()
{
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	string u,t;
	cin >> n >> m;
	cin >> u >> t;
	if (u[0]=='>'&&t[t.length()-1]=='^') cout <<"NO";
	else if (u[0]=='<'&&t[0]=='^') cout <<"NO";
	else if (u[u.length()-1]=='<'&&t[0]=='v') cout <<"NO";
	else if (u[u.length()-1]=='>'&&t[t.length()-1]=='v') cout <<"NO";
	else cout <<"YES";
}
