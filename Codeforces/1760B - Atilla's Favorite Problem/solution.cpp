/**
 * Problem: 1760B - Atilla's Favorite Problem
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1760/problem/B
 * Rating: 800
 * Tags: greedy, implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 181921119
 * Submission Time: 2022-11-21 14:46:21 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 31 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1760/submission/181921119
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long t;
    cin >> t;
    while(t--) {
        long long n = 0;
        cin >> n;
        string a;
        cin >> a;
        sort(a.begin(),a.end());
        cout << int(a[a.size()-1]) - 'a' +1 << endl;
    }
	
	return 0;
}
