/**
 * Problem: 112A - Petya and Strings
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/112/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 182992302
 * Submission Time: 2022-11-28 10:29:10 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/112/submission/182992302
 */

#include <iostream>
 
using namespace std;
 
int main() {
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for (int i = 0;i < a.size();i++) {
        if(a[i] < 97)
            a[i]+=32;
        if(b[i] < 97)
            b[i]+=32;
    }
    int dem = 0;
    for(int i = 0;i < a.size();i++)
        if(a[i] != b[i]) {
            if(int(a[i]) < int(b[i]))
                {cout << -1;dem++;break;}
            if(int(a[i]) > int(b[i]))
                {cout << 1;dem++;break;}
            
        }
    if(dem == 0)
        cout << 0;
    
	return 0;
}
