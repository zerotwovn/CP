/**
 * Problem: 133A - HQ9+
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/133/problem/A
 * Rating: 900
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 185434793
 * Submission Time: 2022-12-16 09:04:40 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/133/submission/185434793
 */


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0;i < a.size();i++)
        if(a[i] == 'H' || a[i] == 'Q' || a[i] == '9')
            {
                cout << "YES";
                return 0;
            }
    cout << "NO";
}