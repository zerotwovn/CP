/**
 * Problem: 71A - Way Too Long Words
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/71/problem/A
 * Rating: 800
 * Tags: strings
 *
 * Verdict: Accepted
 * Submission ID: 174057795
 * Submission Time: 2022-09-30 08:43:07 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/71/submission/174057795
 */

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string a;cin >> a;
        if (a.size()-1 >= 10)
            cout << a[0] << a.size()-2 << a[a.size()-1] << endl;
        else
            cout << a << endl;
    }
    return 0;
}
