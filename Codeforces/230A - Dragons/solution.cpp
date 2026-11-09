/**
 * Problem: 230A - Dragons
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/230/problem/A
 * Rating: 1000
 * Tags: greedy, sortings
 *
 * Verdict: Accepted
 * Submission ID: 204928507
 * Submission Time: 2023-05-07 05:53:50 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/230/submission/204928507
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int s, n;
    cin >> s >> n;
 
    vector<pair<int, int>> a(n);
 
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
 
    sort(a.begin(), a.end());
 
    for (auto dragon : a) {
        int x = dragon.first;
        int y = dragon.second;
        if (s <= x) {
            cout << "NO" << endl;
            return 0;
        } else {
            s += y;
        }
    }
 
    cout << "YES" << endl;
    return 0;
}
