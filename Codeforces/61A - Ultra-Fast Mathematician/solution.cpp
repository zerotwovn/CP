/**
 * Problem: 61A - Ultra-Fast Mathematician
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/61/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183722876
 * Submission Time: 2022-12-03 12:09:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/61/submission/183722876
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    string tmp = "";
    for (int i = 0;i < a.size();i++)
        if(a[i] == b[i])
            tmp+='0';
        else
            tmp+='1';
    cout << tmp;
    return 0;
}
