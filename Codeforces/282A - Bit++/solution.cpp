/**
 * Problem: 282A - Bit++
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/282/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 182990642
 * Submission Time: 2022-11-28 10:11:08 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/282/submission/182990642
 */

#include <iostream>
 
using namespace std;
 
int main() {
	int n, a;
	cin >> n;
 
	a = 0;
 
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[1] == '-') {
			a--;
		} else {
			a++;
		}
	}
 
	cout << a;
 
	return 0;
}