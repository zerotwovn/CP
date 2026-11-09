/**
 * Problem: 281A - Word Capitalization
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/281/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 183572587
 * Submission Time: 2022-12-02 08:37:53 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/281/submission/183572587
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "";
    getline(cin,s);
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0]-=32;
    cout << s;
    return 0;
}
