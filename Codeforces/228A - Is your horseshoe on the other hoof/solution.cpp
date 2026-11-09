/**
 * Problem: 228A - Is your horseshoe on the other hoof?
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/228/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183753317
 * Submission Time: 2022-12-03 16:44:32 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/228/submission/183753317
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 4;
    int a[n] = {};
    int i =0;
    while(n--){
        cin>> a[i];
        i++;
    }
    sort(a,a+i);
    int dem = 0;
    for (int j = 1;j  <i;j++)
    {
        if(a[j] == a[j-1])
            dem++;
    }
    cout << dem;
    return 0;
}
