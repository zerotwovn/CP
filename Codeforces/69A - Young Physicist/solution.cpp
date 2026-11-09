/**
 * Problem: 69A - Young Physicist
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/69/problem/A
 * Rating: 1000
 * Tags: implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 184408343
 * Submission Time: 2022-12-09 02:03:23 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/69/submission/184408343
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n][3];
    long long s1 = 0, s2 = 0,s3 = 0;
    for(int i = 0;i < n;i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            s1+=a[i][0];
            s2+=a[i][1];
            s3+=a[i][2];
        }
    if(s1 == 0 && s2 == 0 && s3 == 0)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
