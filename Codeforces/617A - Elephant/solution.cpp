/**
 * Problem: 617A - Elephant
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/617/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 183586169
 * Submission Time: 2022-12-02 11:06:26 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/617/submission/183586169
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if(x%5 == 0) {
        cout << x/5;
    }
    else
        cout << x/5+1;

    return 0;
}
