/**
 * Problem: 628D - Magic Numbers
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/628/problem/D
 * Rating: 2200
 * Tags: dp
 *
 * Verdict: Accepted
 * Submission ID: 229496188
 * Submission Time: 2023-10-24 00:31:22 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 576 ms
 * Memory: 31600 KB
 * Codeforces Link: https://codeforces.com/contest/628/submission/229496188
 */

#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
int m,d;
int a[2005];
ll dp[2005][2005];
int len;
ll dfs(int pos,bool limit,int r){
	if(!pos)
		return r==0;
 
	auto &now=dp[pos][r];
 
	if(!limit&&now>=0)
		return now;
	int up=limit?a[pos]:9;
 
	int od=(len-pos+1)&1;
	ll res=0;
	if(od){
		for(int i=0;i<=up;i++){
			if(i==d)
				continue;
			res=(res+dfs(pos-1,limit&&i==up,(r*10+i)%m))%MOD;
		}
 
	}else{
		if(d<=up)
			res=(res+dfs(pos-1,limit&&d==up,(r*10+d)%m))%MOD;
	}
	if(!limit)
		now=res;
	return res;
	
}
ll solve(string x){
 
	memset(dp,-1,sizeof(dp));
	
	len=x.size();
	for(int i=0;i<len;i++)
		a[len-i]=x[i]-'0';
 
	return dfs(len,true,0);
}
int main(){
	cin>>m>>d;
	string x,y;
	cin>>x>>y;
	auto check=[&](string x){
		int len=x.size();
		int r=0;
		for(int i=0;i<len;i++){
			if(i&1){
				if(x[i]-'0'!=d)
					return 0;
			}else{
				if(x[i]-'0'==d)
					return 0;
			}
			r=(r*10+x[i]-'0')%m;
		}
		return r?0:1;
	};
	ll ans=(solve(y)-solve(x)+check(x)+MOD)%MOD;
	cout<<ans;
}
