/**
 * Problem: 69A - Young Physicist
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/69/problem/A
 * Rating: 1000
 * Tags: implementation, math
 *
 * Verdict: Wrong Answer
 * Submission ID: 184408232
 * Submission Time: 2022-12-09 01:59:18 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/69/submission/184408232
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n][3];
    long long s = 0;
    for(int i = 0;i < n;i++) {
        for (int j = 0;j < 3;j++) {
            cin >> a[i][j];
            s+=a[i][j];
        }

    }
    if(s == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
