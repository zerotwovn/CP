/**
 * Problem: 510A - Fox And Snake
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/510/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 184158523
 * Submission Time: 2022-12-07 02:51:44 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/510/submission/184158523
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,m;
    cin >> n >> m;
    char a[n][m];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++) {
            a[i][j] = '.';
        }
    }
    for(int i = 0;i < n;i++) { 
        for(int j = 0;j<m;j++) {
            if(i % 2 == 0)
            a[i][j]='#';
            else {
                if((i/2)%2==0)
                    a[i][m-1]='#';
                else
                    a[i][0]='#';
            }
        }
    }
     for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
        {
            cout << a[i][j];
        }
        cout<<endl;
    }
	return 0;
}