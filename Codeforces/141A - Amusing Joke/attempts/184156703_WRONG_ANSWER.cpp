/**
 * Problem: 141A - Amusing Joke
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/141/problem/A
 * Rating: 800
 * Tags: implementation, sortings, strings
 *
 * Verdict: Wrong Answer
 * Submission ID: 184156703
 * Submission Time: 2022-12-07 01:57:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 100 KB
 * Link: https://codeforces.com/contest/141/submission/184156703
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    string tmp = a+b;
    map<char,int> mp1 = {};
    map<char,int> mp2 = {};
    for (int i = 0;i < tmp.size();i++)
        mp1[tmp[i]]++;
    for (int i = 0;i < c.size();i++)
        mp2[c[i]]++;
    int dem = 0;
    for (int i = 0;i < c.size();i++)
        if(mp1[c[i]] != mp2[c[i]])
            {cout << "NO";break;}
        else
            dem++;
    
    if(dem == c.size())
        cout << "YES";
            
    return 0;
}
