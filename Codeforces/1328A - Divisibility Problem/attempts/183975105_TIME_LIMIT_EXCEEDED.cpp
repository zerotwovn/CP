/**
 * Problem: 1328A - Divisibility Problem
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1328/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Time Limit Exceeded
 * Submission ID: 183975105
 * Submission Time: 2022-12-05 10:23:27 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1000 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1328/submission/183975105
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t,a,b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int i = 1;
        while(a > b*i) {
            i++;
        }
        cout << b*i-a << endl;
    }

    return 0;
}
