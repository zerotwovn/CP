/**
 * Problem: 1760A - Medium Number
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1760/problem/A
 * Rating: 800
 * Tags: implementation, sortings
 *
 * Verdict: Accepted
 * Submission ID: 181906387
 * Submission Time: 2022-11-21 14:40:05 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1760/submission/181906387
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long t;
    cin >> t;
    while(t--) {
        long long a[3] = {};
        for (int i = 0;i < 3;i++)
            cin >> a[i];
        sort(a,a+3);
        cout << a[1] << endl;
    }
	
	return 0;
}
