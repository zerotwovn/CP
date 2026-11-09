/**
 * Problem: 1463A - Dungeon
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1463/problem/A
 * Rating: 1100
 * Tags: binary search, math
 *
 * Verdict: Wrong Answer
 * Submission ID: 174682336
 * Submission Time: 2022-10-05 01:39:39 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 93 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1463/submission/174682336
 */


#include <bits/stdc++.h>

using namespace std;
int Min (int a,int b,int c) {
    int nn = min(a,b);
    return min(nn,c);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if ((((a+b+c) % 9) > Min(a,b,c)) || ((a+b+c) / 9 > Min(a,b,c))) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
            
            
    }
    
    return 0;
}
