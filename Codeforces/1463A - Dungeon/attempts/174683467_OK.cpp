/**
 * Problem: 1463A - Dungeon
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1463/problem/A
 * Rating: 1100
 * Tags: binary search, math
 *
 * Verdict: Accepted
 * Submission ID: 174683467
 * Submission Time: 2022-10-05 02:09:43 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 61 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1463/submission/174683467
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if (((a+b+c)%9||(a+b+c)/9>min({a,b,c})))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}