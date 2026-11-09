/**
 * Problem: 231A - Team
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/231/problem/A
 * Rating: 800
 * Tags: brute force, greedy
 *
 * Verdict: Accepted
 * Submission ID: 181845850
 * Submission Time: 2022-11-21 06:25:47 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/231/submission/181845850
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >>n;
    long long t = n;
    long long s = 0;
    int dem = 0;
    while(t--) {
        long long a[n] = {};
        for (int i = 0;i < 3;i++) {
            cin >> a[i];
            s+=a[i];
        }
        if(s >= 2)
            dem++;
        s = 0;
    }
    cout << dem;    
    return 0;
}
