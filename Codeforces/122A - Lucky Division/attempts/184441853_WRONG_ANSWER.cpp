/**
 * Problem: 122A - Lucky Division
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/122/problem/A
 * Rating: 1000
 * Tags: brute force, number theory
 *
 * Verdict: Wrong Answer
 * Submission ID: 184441853
 * Submission Time: 2022-12-09 09:53:14 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/122/submission/184441853
 */


#include <bits/stdc++.h>

using namespace std;
string chuyen (int a) {
    stringstream ss;
    string s;
    ss << a;
    ss >> s;
    return s;
}
bool kt (string a) {
    int dem = 0;
    for(int i = 0;i < a.size();i++) {
        if(a[i] == '4' || a[i] == '7')
            dem++;
    }
    if(dem == a.size())
        return true;
    return false;
}
int main()
{
    string a;
    cin >> a;
    int dem = 0;
    int s = 0;
    for(int i = 0;i < a.size();i++) {
        if(a[i] == '4' || a[i] == '7')
            dem++;
        s+=a[i]-'0';
    }
        
    if(dem == a.size() || kt(chuyen(s)) == true)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
