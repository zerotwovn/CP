/**
 * Problem: 580A - Kefa and First Steps
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/580/problem/A
 * Rating: 900
 * Tags: brute force, dp, implementation
 *
 * Verdict: Accepted
 * Submission ID: 186413329
 * Submission Time: 2022-12-23 02:17:48 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 265 ms
 * Memory: 400 KB
 * Link: https://codeforces.com/contest/580/submission/186413329
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,max=0,p=0;
    cin>>n;
    int v[n] = {};
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]>=v[i-1]){
            p++;
            if(p>max)max=p;   
        }
        else{
            p=1;
        }
    }
    if(p==n)cout<<p<<endl;
    else cout<<max<<endl;    
}