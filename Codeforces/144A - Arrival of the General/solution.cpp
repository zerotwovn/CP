/**
 * Problem: 144A - Arrival of the General
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/144/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183835791
 * Submission Time: 2022-12-04 13:42:58 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/144/submission/183835791
 */

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n;
    cin >> n;
    long long a[n] = {};
    for (int i = 0;i < n;i++)
        {cin >> a[i];}
    long long s = 0;
    int MAX=a[0], MIN=a[0];
    int vtmax=0, vtmin=0;
    for(int i =0;i<n;i++){
        if(a[i]>MAX){
            vtmax=i;
            MAX=a[i];
        }
        if(a[i]<=MIN){
            vtmin=i;
            MIN=a[i];
        }
    }
    if(vtmax>vtmin){
        cout<<(vtmax-1)+(n-vtmin)-1;
    }
    else
    cout<<(vtmax-1)+(n-vtmin);
return 0;
    return 0;
}