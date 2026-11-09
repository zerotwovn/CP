/**
 * Problem: 1739B - Array Recovery
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1739/problem/B
 * Rating: 1100
 * Tags: constructive algorithms, greedy, math
 *
 * Verdict: Compilation Error
 * Submission ID: 174034329
 * Submission Time: 2022-09-30 02:17:23 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1739/submission/174034329
 */

#include <bits/stdc++.h>
 
using namespace std;
 
 long long n,m,gg,k,cc;
long long a[10000],b[10000];
int main(){
    cin>>gg;
    while(gg--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        a[1]=b[1];
        k=0;
        for(int i=2;i<=n;i++){
            a[i]=a[i-1]+b[i];
            if(a[i-1]-b[i]>0&&b[i]!=0){
                k++;
            }
        }
        if(k>0){
            cout<<-1<<endl;
        }else{
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            cout<<endl;
        }
