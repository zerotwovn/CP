/**
 * Problem: 1328A - Divisibility Problem
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1328/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Compilation Error
 * Submission ID: 183975183
 * Submission Time: 2022-12-05 10:24:15 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1328/submission/183975183
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t,a,b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        long longlong i = 1;
        while(a > b*i) {
            i++;
        }
        cout << b*i-a << endl;
    }

    return 0;
}
