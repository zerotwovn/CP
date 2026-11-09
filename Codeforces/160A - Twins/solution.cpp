/**
 * Problem: 160A - Twins
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/160/problem/A
 * Rating: 900
 * Tags: greedy, sortings
 *
 * Verdict: Accepted
 * Submission ID: 185433528
 * Submission Time: 2022-12-16 08:52:31 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/160/submission/185433528
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n] = {};
    long long s = 0;
    for (int i = 0;i < n;i++)
        {cin >> a[i];s+=a[i];}
    long long s1 = 0;
    long long dem = 0;
    s = s/2;
    sort(a,a+n,greater<int>());
    for (int i = 0;i < n;i++) {
        s1+=a[i];
        dem++;
        if(s1 > s)
            break;
    }
    cout << dem;
}
