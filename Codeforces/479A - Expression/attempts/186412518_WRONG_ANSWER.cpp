/**
 * Problem: 479A - Expression
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/479/problem/A
 * Rating: 1000
 * Tags: brute force, math
 *
 * Verdict: Wrong Answer
 * Submission ID: 186412518
 * Submission Time: 2022-12-23 01:53:20 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/479/submission/186412518
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
    long long MAX = max(s,max(max(s1,s2),s3));
    cout << MAX;
    return 0;
}
