/**
 * Problem: 231A - Team
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/231/problem/A
 * Rating: 800
 * Tags: brute force, greedy
 *
 * Verdict: Wrong Answer
 * Submission ID: 181845530
 * Submission Time: 2022-11-21 06:21:07 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/231/submission/181845530
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >>n;
    long long t = n;
    long long dem = 0;
    int dem1 = 0;
    while(t--) {
        long long a[n];
        for (int i = 0;i < n;i++) {
            cin >> a[i];
            if(a[i] == 1)
                dem++;
        }
        if(dem > 1)
            dem1++;
        dem = 0;
    }
    cout << dem1;    
    return 0;
}
