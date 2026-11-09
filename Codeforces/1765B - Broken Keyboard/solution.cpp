/**
 * Problem: 1765B - Broken Keyboard
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1765/problem/B
 * Rating: 800
 * Tags: greedy
 *
 * Verdict: Accepted
 * Submission ID: 183989187
 * Submission Time: 2022-12-05 12:54:25 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1765/submission/183989187
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a = "";
        cin >> a;
        bool kt = true;
            for (int i = 1;i < n;i+=3)
                if(a[i] != a[i+1])
                    kt = false;
            if(kt == false)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
    }
        
    return 0;
}
