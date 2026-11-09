/**
 * Problem: 1765B - Broken Keyboard
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1765/problem/B
 * Rating: 800
 * Tags: greedy
 *
 * Verdict: Wrong Answer
 * Submission ID: 183988287
 * Submission Time: 2022-12-05 12:45:47 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1765/submission/183988287
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
        int dem = 0;
        if(n < 3)
            cout << "NO" << endl;
        else {
            for (int i = 1;i < n;i+=3)
                if(a[i] != a[i-1] && a[i] == a[i+1])
                    dem++;
            if (n -(dem*3) == 0 || n - (dem*3)== 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
            
                    
    }
    return 0;
}
