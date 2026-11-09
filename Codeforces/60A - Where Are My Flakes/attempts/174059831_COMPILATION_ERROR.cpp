/**
 * Problem: 60A - Where Are My Flakes?
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/60/problem/A
 * Rating: 1300
 * Tags: implementation, two pointers
 *
 * Verdict: Compilation Error
 * Submission ID: 174059831
 * Submission Time: 2022-09-30 09:03:51 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/60/submission/174059831
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    long long x=1,y=n;
    while(m--){
        string a,b,s,d;
        int num=0;
        cin>>a>>b>>s>>d>>num;
        if(s=="right")
            x=max(x,num+1);
        else
            y=min(y,num-1);
    }
    if(y>=x) cout<<y-x+1;
    else cout<<-1;
}