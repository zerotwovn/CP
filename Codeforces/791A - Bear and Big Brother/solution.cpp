/**
 * Problem: 791A - Bear and Big Brother
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/791/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183576628
 * Submission Time: 2022-12-02 09:18:51 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/791/submission/183576628
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int dem = 1;
    while(b >= a) {
        dem++;
        b = b*2;
        a = a*3;
    }
    cout << dem-1;
    return 0;
}
