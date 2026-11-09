/**
 * Problem: 266B - Queue at the School
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/266/problem/B
 * Rating: 800
 * Tags: constructive algorithms, graph matchings, implementation, shortest paths
 *
 * Verdict: Accepted
 * Submission ID: 183601433
 * Submission Time: 2022-12-02 13:28:31 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/266/submission/183601433
 */

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,m;
    cin >> n >> m;
    char s[n] = {};
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    while(m--){
        for(int i = 0;i < n;i++){
            if(s[i]=='B'&& s[i+1]=='G'){
                swap(s[i],s[i+1]);
                i++;
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout << s[i];
    }
}
