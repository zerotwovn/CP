/**
 * Problem: 133A - HQ9+
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/133/problem/A
 * Rating: 900
 * Tags: implementation
 *
 * Verdict: Wrong Answer
 * Submission ID: 185434711
 * Submission Time: 2022-12-16 09:03:40 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/133/submission/185434711
 */


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0;i < a.size();i++)
        if(a[i] == 'H' || a[i] == 'Q' || a[i] == '9' || a[i] == '+')
            {
                cout << "YES";
                return 0;
            }
    cout << "NO";
}