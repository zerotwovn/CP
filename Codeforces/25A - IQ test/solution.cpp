/**
 * Problem: 25A - IQ test
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/25/problem/A
 * Rating: 1300
 * Tags: brute force
 *
 * Verdict: Accepted
 * Submission ID: 204928232
 * Submission Time: 2023-05-07 05:51:43 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/25/submission/204928232
 */

#include <iostream>
#include <string>
using namespace std;
 
int main() {
	int n, a, cOdd, cEven, cordO, cordE;
	cin >> n;
	cOdd = 0; cEven = 0;
	for (int i = 1; i <= n; i++){
		cin >> a;
		if (a % 2 == 0){
			cEven++;
			cordE = i;
		}
 
		else{
			cOdd++;
			cordO = i;
		}
 
		if (cOdd == 1 && cEven >= 2){
			cout << cordO;
			return 0;
		}
 
		if (cOdd >= 2 && cEven == 1){
			cout << cordE;
			return 0;
		}
	}
 
	return 0;
}
