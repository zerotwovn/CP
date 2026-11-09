/**
 * Problem: 1328A - Divisibility Problem
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1328/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 183975314
 * Submission Time: 2022-12-05 10:25:48 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 62 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1328/submission/183975314
 */

#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b;
		cin >> a >> b;
		if (a % b == 0)
			cout << 0<<endl;
		else
			cout << b - (a % b) << endl;
	}
}