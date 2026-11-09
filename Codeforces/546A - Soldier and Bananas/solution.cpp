/**
 * Problem: 546A - Soldier and Bananas
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/546/problem/A
 * Rating: 800
 * Tags: brute force, implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 183580389
 * Submission Time: 2022-12-02 09:57:35 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/546/submission/183580389
 */

#include <iostream>

using namespace std;

int main()
{
    long long a,b,c;
    cin >> a >> b >> c;
    long long s = 0;
    for (int i = 1;i <= c;i++)
        s+=(a*i);
    if((b-s) < 0)
        cout << abs(b-s);
    else
        cout << 0;
    return 0;
}
