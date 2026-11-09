/**
 * Problem: 427A - Police Recruits
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/427/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 184334326
 * Submission Time: 2022-12-08 13:24:09 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 78 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/427/submission/184334326
 */

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n, tmp;
    long long police = 0, c = 0;
    cin >> n;
 
    for(long long i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp == -1)
        {
            if(police > 0)
                police--;
            else
                c++;
        }
        else
            police += tmp;
    }
    cout << c << endl;
    return 0;
}
