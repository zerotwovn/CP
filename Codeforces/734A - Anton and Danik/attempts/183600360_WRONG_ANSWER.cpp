/**
 * Problem: 734A - Anton and Danik
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/734/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Wrong Answer
 * Submission ID: 183600360
 * Submission Time: 2022-12-02 13:19:25 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/734/submission/183600360
 */

#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    char a[n] = {};
    for (int i = 0;i < n;i++)   
        cin >> a[i];
    int demA = 0,demD = 0;
    for (int i = 0;i < n;i++)
        if(a[i] == 'A')
            demA++;
        else
            demD++;
    if(demA > demD)
        cout << "Aton";
    else if(demA < demD)
        cout << "Danik";
    else
        cout << "Friendship";
    return 0;
}