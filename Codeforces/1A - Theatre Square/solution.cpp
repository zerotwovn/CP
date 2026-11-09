/**
 * Problem: 1A - Theatre Square
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1/problem/A
 * Rating: 1000
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 181846527
 * Submission Time: 2022-11-21 06:34:25 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1/submission/181846527
 */

#include<iostream>
using namespace std;
 
int main(){
	long long n,m,a;
	cin >> n >> m >> a;
	long long s1 = 0,s2 = 0;
	if(n % a != 0) {
		s1 = n/a+1;
	}
	else s1 = n/a;
	
	if(m % a != 0) {
		s2 = m/a+1;
	}
	else s2 = m/a;
	
	cout << s1 * s2;
	
	return 0;
}