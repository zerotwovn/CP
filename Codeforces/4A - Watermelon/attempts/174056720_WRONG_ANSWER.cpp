/**
 * Problem: 4A - Watermelon
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/4/problem/A
 * Rating: 800
 * Tags: brute force, math
 *
 * Verdict: Wrong Answer
 * Submission ID: 174056720
 * Submission Time: 2022-09-30 08:29:25 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/4/submission/174056720
 */

#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a/2 + a/2 == a)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
