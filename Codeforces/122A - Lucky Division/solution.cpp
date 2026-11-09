/**
 * Problem: 122A - Lucky Division
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/122/problem/A
 * Rating: 1000
 * Tags: brute force, number theory
 *
 * Verdict: Accepted
 * Submission ID: 185431965
 * Submission Time: 2022-12-16 08:37:08 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/122/submission/185431965
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lucknum;
    cin >> lucknum;
    if ((lucknum % 4 == 0) || (lucknum % 7 == 0) || (lucknum % 47 == 0) || (lucknum % 74 == 0) || (lucknum % 444 == 0) || (lucknum % 447 == 0) || (lucknum % 474 == 0) || (lucknum % 744 == 0) || (lucknum % 477 == 0) || (lucknum % 774 == 0) || (lucknum % 747 == 0) || (lucknum % 777 == 0))
        cout << "YES";
    else
        cout << "NO";
}
