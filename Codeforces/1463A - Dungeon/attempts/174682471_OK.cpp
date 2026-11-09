/**
 * Problem: 1463A - Dungeon
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1463/problem/A
 * Rating: 1100
 * Tags: binary search, math
 *
 * Verdict: Accepted
 * Submission ID: 174682471
 * Submission Time: 2022-10-05 01:43:17 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 77 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1463/submission/174682471
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<((a+b+c)%9||(a+b+c)/9>min({a,b,c})?"NO\n":"YES\n");
    }
}