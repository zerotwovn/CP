/**
 * Problem: 443A - Anton and Letters
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/443/problem/A
 * Rating: 800
 * Tags: constructive algorithms, implementation
 *
 * Verdict: Accepted
 * Submission ID: 184054430
 * Submission Time: 2022-12-06 03:31:15 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 100 KB
 * Codeforces Link: https://codeforces.com/contest/443/submission/184054430
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1000] = {};
    map <char,int> mp = {};
    int n = 0;
    while(cin) {
        cin >> a[n];
        mp[a[n]] = 1;
        n++;
    }
    int s = 0;
    for (int i = 0;i < n;i++)
        if(a[i] >= 'a' && a[i] <= 'z' && mp[a[i]] > 0) {
            s+=mp[a[i]];
            mp[a[i]] = 0;
        }
    cout << s;
    return 0;
}
