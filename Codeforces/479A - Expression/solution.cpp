/**
 * Problem: 479A - Expression
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/479/problem/A
 * Rating: 1000
 * Tags: brute force, math
 *
 * Verdict: Accepted
 * Submission ID: 186412580
 * Submission Time: 2022-12-23 01:55:04 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/479/submission/186412580
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    cin >> a >> b >> c;
    long long s = a+b*c;
    long long s1 = (a+b) * c;
    long long s2 = a * (b+c);
    long long s3 = a*b*c;
    long long s4 = a+b+c;
    long long MAX = max(s,max(max(s1,s2),max(s3,s4)));
    cout << MAX;
    return 0;
}
