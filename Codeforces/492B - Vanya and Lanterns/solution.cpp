/**
 * Problem: 492B - Vanya and Lanterns
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/492/problem/B
 * Rating: 1200
 * Tags: binary search, implementation, math, sortings
 *
 * Verdict: Accepted
 * Submission ID: 204928647
 * Submission Time: 2023-05-07 05:54:50 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/492/submission/204928647
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,l;
	cin >> n >> l;
	ll a[n+2];
	for (ll i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	double Max=max(a[1],l-a[n]);
//	double ans;
	for (ll i=2;i<=n;i++)
	{
		Max=max(Max,double(a[i]-a[i-1])/2);
	 } 
	 cout << setprecision(10) << fixed << Max;
}
