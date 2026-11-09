/**
 * Problem: 1335A - Candies and Two Sisters
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1335/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 184156942
 * Submission Time: 2022-12-07 02:05:36 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1335/submission/184156942
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        if(n % 2 == 0)
            cout << n/2-1 << endl;
        else
            cout << n/2 << endl;
    }
    
            
    return 0;
}
