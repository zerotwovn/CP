/**
 * Problem: 1042A - Benches
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1042/problem/A
 * Rating: 1100
 * Tags: binary search, implementation
 *
 * Verdict: Accepted
 * Submission ID: 174949435
 * Submission Time: 2022-10-07 08:41:28 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1042/submission/174949435
 */

#include<iostream>
using namespace std;
int main()
{
	long long n ,m ,s = 0 ,x,MAX = 0;
    cin >> n >> m;
	for(int i = 0 ; i < n ; i++) 
	{
	    cin >> x;
	    s += x;
	    MAX = max(x,MAX);
	}
	cout << max(MAX,(s+m-1)/n+1) << " " << MAX + m;
	return 0;
}