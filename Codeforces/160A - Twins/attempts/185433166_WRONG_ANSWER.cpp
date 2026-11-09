/**
 * Problem: 160A - Twins
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/160/problem/A
 * Rating: 900
 * Tags: greedy, sortings
 *
 * Verdict: Wrong Answer
 * Submission ID: 185433166
 * Submission Time: 2022-12-16 08:48:50 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/160/submission/185433166
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
    sort(a,a+n);
    for (int i = 0;i < n;i++) {
        s-=a[i];
        s1+=a[i];
        dem++;
        if(s1 > s)
            break;
    }
    cout << dem;
}