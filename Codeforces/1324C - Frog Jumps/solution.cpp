/**
 * Problem: 1324C - Frog Jumps
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1324/problem/C
 * Rating: 1100
 * Tags: binary search, data structures, dfs and similar, greedy, implementation
 *
 * Verdict: Accepted
 * Submission ID: 177938989
 * Submission Time: 2022-10-26 02:22:02 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 61 ms
 * Memory: 500 KB
 * Link: https://codeforces.com/contest/1324/submission/177938989
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,dem = 0,MAX;
	string s;
	cin>>n;
	while(n--){
	cin>>s;
	for(int i=0;i<=s.size();i++)
	    if(s[i]=='L') 
	        dem++;
	    else{
	        MAX=max(MAX,dem);
	        dem=0;	
	    }
	cout<<MAX+1<<endl;MAX=0;
	}	
	return 0;
}