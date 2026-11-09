/**
 * Problem: 1057A - Bmail Computer Network
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1057/problem/A
 * Rating: 900
 * Tags: *special, dfs and similar, trees
 *
 * Verdict: Accepted
 * Submission ID: 177938176
 * Submission Time: 2022-10-26 02:02:59 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 280 ms
 * Memory: 7800 KB
 * Link: https://codeforces.com/contest/1057/submission/177938176
 */

#include<bits/stdc++.h>
using namespace std;
long long n;long long a[200001];
void kiemtra(int i){
	if(i!=0) 
	    {kiemtra(a[i]);cout<<i<<" ";}
	
}
int main(){
	cin>>n;
	
	for(int i=2;i<=n;i++) 
	    cin>>a[i];
	kiemtra(n);
	return 0;
}