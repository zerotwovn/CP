/**
 * Problem: 155A - I_love_\%username\%
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/155/problem/A
 * Rating: 800
 * Tags: brute force
 *
 * Verdict: Accepted
 * Submission ID: 184158694
 * Submission Time: 2022-12-07 02:56:45 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/155/submission/184158694
 */

#include <iostream>
 
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i++)
 
int main()
{
    int n,ans;
    cin >> n;
    int a[n] = {};
    FOR(i,0,n) cin >> a[i];
    if (n < 2) cout << 0;
    else
    {
        int mac = max(a[0],a[1]),minn = min(a[0],a[1]);
        if (mac == minn) ans = 0;
        else ans = 1;
        FOR(i,2,n)
        {
            if (a[i] < minn) {ans++;minn=a[i];}
            else if (a[i] > mac) {ans++;mac=a[i];}
            else{}
        }
        cout << ans;
    }
}