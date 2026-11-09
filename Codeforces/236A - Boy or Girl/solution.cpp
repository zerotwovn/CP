/**
 * Problem: 236A - Boy or Girl
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/236/problem/A
 * Rating: 800
 * Tags: brute force, implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 183573483
 * Submission Time: 2022-12-02 08:47:15 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 62 ms
 * Memory: 100 KB
 * Codeforces Link: https://codeforces.com/contest/236/submission/183573483
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "";
    getline(cin,s);
    map<char,int> mp = {};
    for (int i = 0;i < s.size();i++)
        mp[s[i]] +=1;
    int sum = 0;
    for (int i = 0;i < s.size();i++) {
        if(mp[s[i]] != 0) {
            sum+=1;
            mp[s[i]] = 0;
        }
        if(mp[s[i]] == 1)
            sum+=mp[s[i]];
    }    
    if(sum % 2 ==0)
        cout << "CHAT WITH HER!";
    else
        cout << "IGNORE HIM!";
    return 0;
}
