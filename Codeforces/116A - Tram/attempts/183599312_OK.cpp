/**
 * Problem: 116A - Tram
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/116/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183599312
 * Submission Time: 2022-12-02 13:10:13 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/116/submission/183599312
 */

#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long s = 0;
    long long Max = 0;
    for(long long i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        s = s - a + b;
        Max = max(Max,s);
    }
    cout << Max << endl;
    return 0;
}