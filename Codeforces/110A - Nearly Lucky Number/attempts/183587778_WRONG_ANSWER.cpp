/**
 * Problem: 110A - Nearly Lucky Number
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/110/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Wrong Answer
 * Submission ID: 183587778
 * Submission Time: 2022-12-02 11:23:22 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/110/submission/183587778
 */


#include <bits/stdc++.h>

using namespace std;
bool luckynumber (string a) {
    for (int i = 0;i < a.size();i++)
        if(a[i] != '7' && a[i] != '4')
            return false;
        return true;
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
    string a;
    cin >> a;
    string n = chuyen(a.size());
    if(luckynumber(n) == true)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
