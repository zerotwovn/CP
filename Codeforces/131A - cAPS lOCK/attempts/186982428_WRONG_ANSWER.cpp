/**
 * Problem: 131A - cAPS lOCK
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/131/problem/A
 * Rating: 1000
 * Tags: implementation, strings
 *
 * Verdict: Wrong Answer
 * Submission ID: 186982428
 * Submission Time: 2022-12-28 01:08:43 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/131/submission/186982428
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    string a;
    cin >> a; 
    if(a[0] >= 'a' && a[0] <= 'z')
        a[0]-=32;
    for(int i = 1;i < a.size();i++)
        if(a[i] >= 65 && a[i] <= 90)
            a[i]+=32;
    cout << a;
    return 0;
}
