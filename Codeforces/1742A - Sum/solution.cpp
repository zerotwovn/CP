/**
 * Problem: 1742A - Sum
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1742/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 395537104
 * Submission Time: 2026-10-22 05:38:58 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1742/submission/395537104
 */

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if (a + b == c || a + c == b || b + c == a) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }

    return 0;
}
