/**
 * Problem: 208A - Dubstep
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/208/problem/A
 * Rating: 900
 * Tags: strings
 *
 * Verdict: Accepted
 * Submission ID: 186980350
 * Submission Time: 2022-12-27 23:49:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/208/submission/186980350
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin >> a; 
    for(int i = 2;i < a.size();i++)
        if(a[i - 2] == 'W' && a[i - 1] == 'U' && a[i] == 'B') {
            a[i] = ' ';
            a[i-1] = ' ';
            a[i-2] = ' ';
        }
    int dem = 0;
    for (int i = 0;i < a.size();i++) {
        if(a[i] != ' ')
            cout << a[i];
        if(a[i] == ' ' && a[i+1] >= 65 && a[i+1] <= 90 && dem != 0) {
            cout << " ";
        }
        if((a[i] == ' ' && a[i+1] >= 65 && a[i+1] <= 90) || (a[i] != ' ' && i == 0))
            dem++;
    }
    return 0;
}
