/**
 * Problem: 4A - Watermelon
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/4/problem/A
 * Rating: 800
 * Tags: brute force, math
 *
 * Verdict: Accepted
 * Submission ID: 174056951
 * Submission Time: 2022-09-30 08:32:48 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/4/submission/174056951
 */

#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a <= 2)
        cout << "No";
    else
    {
        if (a/2 + a/2 == a)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}
