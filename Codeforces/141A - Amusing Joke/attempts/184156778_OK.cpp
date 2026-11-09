/**
 * Problem: 141A - Amusing Joke
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/141/problem/A
 * Rating: 800
 * Tags: implementation, sortings, strings
 *
 * Verdict: Accepted
 * Submission ID: 184156778
 * Submission Time: 2022-12-07 02:00:15 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/141/submission/184156778
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    string tmp = a+b;
    sort(c.begin(),c.end());
    sort(tmp.begin(),tmp.end());
    if(tmp == c)
        cout << "YES";
    else
        cout << "NO";
            
    return 0;
}
