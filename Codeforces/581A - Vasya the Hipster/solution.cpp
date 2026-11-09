/**
 * Problem: 581A - Vasya the Hipster
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/581/problem/A
 * Rating: 800
 * Tags: implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 204929698
 * Submission Time: 2023-05-07 06:02:32 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/581/submission/204929698
 */

#include <iostream>
 
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i++)
 
int main()
{
    int a,b;
    cin >> a >> b;
    cout << min(a,b) << " " << abs(a-b)/2;
}
