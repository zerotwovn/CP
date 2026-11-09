/**
 * Problem: 750A - New Year and Hurry
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/750/problem/A
 * Rating: 800
 * Tags: binary search, brute force, implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 204928912
 * Submission Time: 2023-05-07 05:56:44 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/750/submission/204928912
 */

#include <iostream>
 
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i++)
 
int main()
{
    int n,k,ans = 0;
    cin >> n >> k;
    int d = 240-k,i = 1;
    while ( i <= n && d - 5*i >= 0)
    {
        d -= 5*i;
        ans++;
        i++;
    }
    cout << ans;
}
