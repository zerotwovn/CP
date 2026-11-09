/**
 * Problem: 271A - Beautiful Year
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/271/problem/A
 * Rating: 800
 * Tags: brute force
 *
 * Verdict: Accepted
 * Submission ID: 183605108
 * Submission Time: 2022-12-02 13:58:19 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/271/submission/183605108
 */

#include <bits/stdc++.h>
 
using namespace std;
int kiemtra (string a) {
    int dem[10] = {};
    for (int i = 0;i < 4;i++) {
        dem[a[i]-'0']++;
        if(dem[a[i]-'0'] >= 2)
            return 1;
        
    }
    return 0;
        
}
string chuyen (long long a) {
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    return s;
}
int main()
{
    long long a = 0;
    cin >> a;
    a +=1;
    while(kiemtra(chuyen(a)) != 0) {
        a+=1;
        
    }
    cout << a;
}
