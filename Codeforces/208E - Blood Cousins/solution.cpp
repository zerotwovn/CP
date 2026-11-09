/**
 * Problem: 208E - Blood Cousins
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/208/problem/E
 * Rating: 2100
 * Tags: binary search, data structures, dfs and similar, trees
 *
 * Verdict: Accepted
 * Submission ID: 233676957
 * Submission Time: 2023-11-21 11:18:16 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1432 ms
 * Memory: 44700 KB
 * Codeforces Link: https://codeforces.com/contest/208/submission/233676957
 */

#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz=2e5+5;
ll n,k,m,q,T,p,start,ans;
int timer=1;
int st[sz];
int en[sz];
ll dp[sz];
ll up[18][sz];
bool vis[sz];
vector<ll>hei[sz];
ll com[sz];
vector<ll>adj[sz];
void dfs(int u){
    st[u]=timer; vis[u]=1;
    hei[dp[u]].push_back(timer++);
    for(int i=1;i<=17;i++){
        up[i][u]=up[i-1][up[i-1][u]];
    }
    for(auto v:adj[u]){
        if(v==up[0][u]) continue;
        dp[v]=dp[up[0][v]=u]+1;
        dfs(v);
    }
    en[u]=timer-1;
}
ll jump(int x , int d){
    for(int i=0;i<=17;i++){
        if((d>>i)&1) x=up[i][x];
    } return x;
}
int main(){
     cin>>n;
     for(int i=1;i<=n;i++){
         int x;cin>>x;
         adj[x].push_back(i);
     }
     cin>>q;
     for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
     for(int i=1;i<=q;i++){
         ll u,w;cin>>u>>w;
         const auto &v=hei[dp[u]];
         ll x=jump(u,w);
         if(dp[u]<w){cout<<0<<" ";continue;}
         ans=upper_bound(v.begin(),v.end(),en[x])-lower_bound(v.begin(),v.end(),st[x])-1;
         cout<<ans<<" ";
     }
}
