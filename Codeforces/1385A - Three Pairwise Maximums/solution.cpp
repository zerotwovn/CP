/**
 * Problem: 1385A - Three Pairwise Maximums
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1385/problem/A
 * Rating: 800
 * Tags: math
 *
 * Verdict: Accepted
 * Submission ID: 204323359
 * Submission Time: 2023-05-03 10:21:00 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 186 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1385/submission/204323359
 */

#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x = 1, y = 1, z = 1;
        cin >> x >> y >> z;
        if (x == y && y == z)cout << "YES\n" << x << " " << y << " " << z << endl;
        else if (x == y && x > z)
        cout << "YES\n" << x << " " << z << " " << 1 << endl;
        else if (x == z && y<x)
        cout << "YES\n" << x << " " << y << " " << 1 << endl;
        else if (y == z && x<y)
        cout << "YES\n" << x << " " << 1<< " "<< y   << endl;
        else cout << "NO\n";
    }
    return 0;
}
