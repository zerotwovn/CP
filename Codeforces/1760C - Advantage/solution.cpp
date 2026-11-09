/**
 * Problem: 1760C - Advantage
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1760/problem/C
 * Rating: 800
 * Tags: data structures, implementation, sortings
 *
 * Verdict: Accepted
 * Submission ID: 181946008
 * Submission Time: 2022-11-21 15:04:41 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 436 ms
 * Memory: 3100 KB
 * Link: https://codeforces.com/contest/1760/submission/181946008
 */

#include<bits/stdc++.h>
using namespace std;
 

int main(){
    long long t;
    cin >> t;
    while(t--) {
        long long n = 0;
        cin >> n;
        long long a[n] = {};
        long long tmp[n] = {};
        for (int i = 0;i < n;i++) {
            cin >> a[i];tmp[i] = a[i];
        }
        sort(tmp,tmp+n,greater<int>());
        for (int i = 0;i < n;i++)
            if(a[i] != tmp[0])
                cout << a[i] - tmp[0] << " ";
            else
                cout << tmp[0] - tmp[1] << " ";
        cout << endl;
                
    }
	
	return 0;
}