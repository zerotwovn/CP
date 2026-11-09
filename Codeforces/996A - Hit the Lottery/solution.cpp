/**
 * Problem: 996A - Hit the Lottery
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/996/problem/A
 * Rating: 800
 * Tags: dp, greedy
 *
 * Verdict: Accepted
 * Submission ID: 184080531
 * Submission Time: 2022-12-06 09:32:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/996/submission/184080531
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,dem=0;
    int a[5]={100,20,10,5,1};
    cin>>n;
    for(int i=0; i<5; i++)
    {
        dem+=n/a[i];
        n=n%a[i];
    }
    cout<<dem<<endl;
    return 0;
}