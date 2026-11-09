/**
 * Problem: 1739C - Card Game
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1739/problem/C
 * Rating: 1500
 * Tags: combinatorics, constructive algorithms, dp, games
 *
 * Verdict: Accepted
 * Submission ID: 174034500
 * Submission Time: 2022-09-30 02:21:13 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1739/submission/174034500
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;  
int C(int n,int m){
    int ans = 1;
    for(int i =1;i<=m;i++){
        ans = ans * (n-m+i)/i; 
    }
    return ans;
}
signed main()
{
    int a[61],b[61];
    a[2]=1;b[2]=0;
    for(int i=4;i<=60;i+=2)
    {
        a[i]=(C(i-1,i/2-1)+b[i-2])%mod;
        b[i]=(C(i,i/2)-a[i]-1)%mod;
    }
    int t;cin>>t;
    while(t--)
    {
        int x;cin>>x;
        cout<<a[x]<<" "<<b[x]<<" "<<1<<"\n";
    }
 
}
