/**
 * Problem: 961B - Lecture Sleep
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/961/problem/B
 * Rating: 1200
 * Tags: data structures, dp, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174059618
 * Submission Time: 2022-09-30 09:02:00 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 1200 KB
 * Link: https://codeforces.com/contest/961/submission/174059618
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, t[100001], a[100001], c[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>> m;
    long long res=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        if(t[i])
        {
            res+=a[i];
            a[i]=0;
        }
    }
    c[0]=0;
    for(int i=1;i<=n;i++)
    {
        c[i]=a[i-1]+c[i-1];
    }
    long long tmp=0;
    for(int i=n;i>=m;i--)
    {
        tmp=max(tmp,1ll*c[i]-c[i-m]);
    }
    cout<<res+tmp<<endl;
    return 0;
}