/**
 * Problem: 723A - The New Year: Meeting Friends
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/723/problem/A
 * Rating: 800
 * Tags: implementation, math, sortings
 *
 * Verdict: Accepted
 * Submission ID: 204931599
 * Submission Time: 2023-05-07 06:17:06 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/723/submission/204931599
 */

#include <iostream>
#include <algorithm>
 
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i++)
 
int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    int ans = INT_MAX;
    FOR(i,1,max(a[0],max(a[1],a[2]))){
        int d = abs(i-a[0])+abs(i-a[1])+abs(i-a[2]);
        ans = min(ans,d);
    }
    cout << ans;
}
