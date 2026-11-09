/**
 * Problem: 151A - Soft Drinking
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/151/problem/A
 * Rating: 800
 * Tags: implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 242005808
 * Submission Time: 2024-01-17 01:59:58 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/151/submission/242005808
 */

#include <bits/stdc++.h>
 
using namespace std;
 
void solve(long long c) {
 
}
 
int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    
    int x = k * l / n / nl;
    int y = c * d / n;
    int z = p / n / np;
 
    cout << min({x,y,z});
}
