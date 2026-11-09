/**
 * Problem: 977A - Wrong Subtraction
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/977/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183586953
 * Submission Time: 2022-12-02 11:14:41 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/977/submission/183586953
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,t;
    cin >> a >> t;
    while(t--) {
        if(a %10 == 0)
            a = a/10;
        else
            a-=1;
    }
    cout << a;
    return 0;
}
