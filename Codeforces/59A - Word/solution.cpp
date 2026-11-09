/**
 * Problem: 59A - Word
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/59/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 183586644
 * Submission Time: 2022-12-02 11:11:25 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/59/submission/183586644
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int demthuong = 0;
    int demhoa = 0;
    int n = s.size();
    for (int i =0 ;i < n;i++) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            demhoa++;
        if(s[i] >= 'a' && s[i] <= 'z')
            demthuong++;
    }
    if(demhoa > demthuong) {
        for (int i = 0;i < n;i++)
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i]-=32;
    }
    else {
        for (int i = 0;i < n;i++)
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i]+=32;
    }
    cout << s;
    return 0;
}
