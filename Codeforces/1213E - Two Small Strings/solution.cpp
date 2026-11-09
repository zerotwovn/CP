/**
 * Problem: 1213E - Two Small Strings
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1213/problem/E
 * Rating: 1900
 * Tags: brute force, constructive algorithms
 *
 * Verdict: Accepted
 * Submission ID: 196474238
 * Submission Time: 2023-03-08 07:28:36 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 300 KB
 * Link: https://codeforces.com/contest/1213/submission/196474238
 */

#include <bits/stdc++.h>

 
using namespace std;
 
const char rep[6][4] = {"abc", "acb", "bac", "bca", "cab", "cba"};
const int N = 3e5 + 3;
 
int n;
char st[3][3];
 
char ans[N];
 
void Check() {
	for (int i = 2; i <= n * 3; i++) {
		if ((ans[i] == st[0][1] && ans[i - 1] == st[0][0]) || (ans[i] == st[1][1] && ans[i - 1] == st[1][0])) {
			return;
		}
	}
	cout << "YES\n" << ans + 1;
	exit(0);
}
 
signed main() {
	cin >> n >> st[0] >> st[1];
	for (int k = 0; k < 6; k++) {
		for (int i = 1; i <= n; i++) {
			ans[(i - 1) * 3 + 1] = rep[k][0], ans[(i - 1) * 3 + 2] = rep[k][1], ans[(i - 1) * 3 + 3] = rep[k][2];
		}
		Check();
		for (int i = 1; i <= n; i++) {
			ans[i] = rep[k][0], ans[i + n] = rep[k][1], ans[i + n * 2] = rep[k][2];
		}
		Check();
	}
	cout << "NO";
	return 0;
}