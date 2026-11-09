/**
 * Problem: 1739B - Array Recovery
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1739/problem/B
 * Rating: 1100
 * Tags: constructive algorithms, greedy, math
 *
 * Verdict: Hacked
 * Submission ID: 174034382
 * Submission Time: 2022-09-30 02:18:19 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 200 KB
 * Link: https://codeforces.com/contest/1739/submission/174034382
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
    }
}