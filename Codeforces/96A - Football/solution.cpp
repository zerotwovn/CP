/**
 * Problem: 96A - Football
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/96/problem/A
 * Rating: 900
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 184337314
 * Submission Time: 2022-12-08 13:48:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/96/submission/184337314
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int kt = 0, dem = 1;
    for (int i=0;i<s.size()-1;i++) {
	    if (s[i]==s[i+1]) {
	 	    dem ++;
	 	    if (dem >= 7) {
	 	        kt=1;
	 	     break;
		    }
	    }
	    else 
	 	    dem=1;
        }
    if (kt == 1) 
        cout << "YES";
    else 
        cout << "NO";
 
 return 0;
}