/**
 * Problem: 1761A - Two Permutations
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1761/problem/A
 * Rating: 800
 * Tags: brute force, constructive algorithms
 *
 * Verdict: Accepted
 * Submission ID: 184159361
 * Submission Time: 2022-12-07 03:15:08 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1761/submission/184159361
 */

#include <iostream>
 
using namespace std;

 
int main()
{
    long long t;
    cin >> t;
    while(t--) {
        long long n,a,b;
        cin >> n >> a >> b;
        if(n == a && n == b) {
            cout << "Yes" << endl;
            continue;
        }
        if(a+b >= n-1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}