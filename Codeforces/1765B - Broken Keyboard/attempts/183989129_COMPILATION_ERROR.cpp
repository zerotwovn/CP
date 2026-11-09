/**
 * Problem: 1765B - Broken Keyboard
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1765/problem/B
 * Rating: 800
 * Tags: greedy
 *
 * Verdict: Compilation Error
 * Submission ID: 183989129
 * Submission Time: 2022-12-05 12:53:54 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1765/submission/183989129
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
            
                    
    }
    return 0;
}
