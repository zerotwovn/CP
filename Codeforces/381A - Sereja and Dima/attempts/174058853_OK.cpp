/**
 * Problem: 381A - Sereja and Dima
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/381/problem/A
 * Rating: 800
 * Tags: greedy, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174058853
 * Submission Time: 2022-09-30 08:54:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/381/submission/174058853
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,r=n-1,x=0,y=0,t=1;
    while(l<=r){
        if(t==1){
            if(a[l]>=a[r]){
                x+=a[l];
                l++;
            }
            else{
                x+=a[r];
                r--;
            }
        }
        else{
            if(a[l]>=a[r]){
                y+=a[l];
                l++;
            }
            else{
                y+=a[r];
                r--;
            }
        }
        t*=-1;
    }
    cout<<x<<" "<<y;
}