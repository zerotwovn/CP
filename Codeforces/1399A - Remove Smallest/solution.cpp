/**
 * Problem: 1399A - Remove Smallest
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1399/problem/A
 * Rating: 800
 * Tags: greedy, sortings
 *
 * Verdict: Wrong Answer
 * Submission ID: 242006130
 * Submission Time: 2024-01-17 02:07:18 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1399/submission/242006130
 */

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    if(n==1)
    {
        cout << "yes";
        return;
    }
    sort(v.begin(), v.end());
    for(int i=1; i<n; i++)
    {
        if(v[i]-v[i-1]>1)
        {
            cout << "no";

            return;
        }
    }
    cout << "yes";
}
 
int main()
{
    ios_base:: sync_with_stdio(false),cin.tie(NULL);
    solve();
}