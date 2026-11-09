/**
 * Problem: 705A - Hulk
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/705/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183723814
 * Submission Time: 2022-12-03 12:17:49 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/705/submission/183723814
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (int i = 1;i <=n;i++)
    {
        if(i % 2 != 0)
            cout << "I hate ";
        else
            cout << "I love ";
        if(i!=n)
            cout << "that ";
    }
    cout <<  "it";


    return 0;
}
