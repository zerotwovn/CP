/**
 * Problem: 339B - Xenia and Ringroad
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/339/problem/B
 * Rating: 1000
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 204929061
 * Submission Time: 2023-05-07 05:57:48 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 92 ms
 * Memory: 400 KB
 * Codeforces Link: https://codeforces.com/contest/339/submission/204929061
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,i; cin>>n>>m;
    int a[m];
    long long int count=0;
    for (i = 0; i < m; i++){cin>>a[i];}
    count=a[0]-1;
    for (i = 1; i < m; i++){
        if (a[i]<a[i-1]){count+=(n+a[i]-a[i-1]);}
        else{ count+=(a[i]-a[i-1]);}
    }
    cout<<count<<endl;
    return 0;
}
