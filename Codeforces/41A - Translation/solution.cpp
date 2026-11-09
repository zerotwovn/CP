/**
 * Problem: 41A - Translation
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/41/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 183602015
 * Submission Time: 2022-12-02 13:33:09 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/41/submission/183602015
 */

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string a = "",b = "";
    getline(cin,a);
    getline(cin,b);
    reverse(a.begin(),a.end());
    if(a == b)
        cout << "YES";
    else
        cout << "NO";
}
