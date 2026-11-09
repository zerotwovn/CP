/**
 * Problem: 263A - Beautiful Matrix
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/263/problem/A
 * Rating: 800
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 182991536
 * Submission Time: 2022-11-28 10:20:39 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/263/submission/182991536
 */

#include <iostream>
 
using namespace std;
 
int main() {
    long long a[5][5];
    for (int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)
            cin >>a[i][j];
    for (int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)
            if(a[i][j] == 1)
                cout << (max(i,2) - min(i,2)) + (max(j,2) - min(j,2));
 
	return 0;
}
