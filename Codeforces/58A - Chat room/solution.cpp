/**
 * Problem: 58A - Chat room
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/58/problem/A
 * Rating: 1000
 * Tags: greedy, strings
 *
 * Verdict: Accepted
 * Submission ID: 184408580
 * Submission Time: 2022-12-09 02:11:22 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/58/submission/184408580
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin >> a;
    string tmp = "hello";
    int j = 0;
    for (int i = 0;i < a.size();i++)
        if(a[i] == tmp[j])
            j++;
    if(j == 5)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
