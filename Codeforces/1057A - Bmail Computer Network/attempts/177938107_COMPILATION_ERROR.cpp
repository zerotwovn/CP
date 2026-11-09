/**
 * Problem: 1057A - Bmail Computer Network
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1057/problem/A
 * Rating: 900
 * Tags: *special, dfs and similar, trees
 *
 * Verdict: Compilation Error
 * Submission ID: 177938107
 * Submission Time: 2022-10-26 02:01:32 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1057/submission/177938107
 */

#include<bits/stdc++.h>
using namespace std;
long long n;long long a[200005];
void kiemtra(int dem){
	if(dem!=0) 
	    {kiemtra(a[i]);cout<<dem<<" ";}
	
}
int main(){
	cin>>n;
	
	for(int i=2;i<=n;i++) 
	    cin>>a[i];
	kiemtra(n);
	return 0;
}