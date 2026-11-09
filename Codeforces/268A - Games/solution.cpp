/**
 * Problem: 268A - Games
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/268/problem/A
 * Rating: 800
 * Tags: brute force
 *
 * Verdict: Accepted
 * Submission ID: 184079680
 * Submission Time: 2022-12-06 09:23:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/268/submission/184079680
 */


#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a1[n],s = 0;
	int a2[n];
	for(int i = 0;i < n;i++){
		cin >> a1[i] >> a2[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(a1[i] == a2[j]){
				s++;
			}
		}
	}
	cout << s;
}