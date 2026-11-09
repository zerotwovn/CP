/**
 * Problem: 110A - Nearly Lucky Number
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/110/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 183588085
 * Submission Time: 2022-12-02 11:26:24 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/110/submission/183588085
 */

#include <bits/stdc++.h>

using namespace std;
int main()
{
    string a;
    cin >> a;
    int dem = 0;
    for (int i = 0;i < a.size();i++)
        if(a[i] == '4' || a[i] == '7')
            dem++;
    if(dem == 4 || dem == 7)
        cout << "YES";
    else
     cout << "NO";
    return 0;
}
