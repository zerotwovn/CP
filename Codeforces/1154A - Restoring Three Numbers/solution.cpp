/**
 * Problem: 1154A - Restoring Three Numbers
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1154/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 242005728
 * Submission Time: 2024-01-17 01:57:51 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1154/submission/242005728
 */

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int a[4];
 
int main() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4);
	cout << (a[3] - a[0]) << " " << (a[3] - a[1]) << " " << (a[3] - a[2]) << endl;
}
