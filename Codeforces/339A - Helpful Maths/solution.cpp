/**
 * Problem: 339A - Helpful Maths
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/339/problem/A
 * Rating: 800
 * Tags: greedy, implementation, sortings, strings
 *
 * Verdict: Accepted
 * Submission ID: 183572381
 * Submission Time: 2022-12-02 08:35:43 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/339/submission/183572381
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "";
    getline(cin,s);
    sort(s.begin(),s.end());
    for (int i= 0;i < s.size();i++)
        if((i != s.size()-1) && (s[i] >= '0' && s[i] <= '9'))
            cout << s[i] << "+";
    cout << s[s.size()-1];
    return 0;
}
