/**
 * Problem: 1352A - Sum of Round Numbers
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1352/problem/A
 * Rating: 800
 * Tags: implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 204929369
 * Submission Time: 2023-05-07 06:00:05 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 77 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1352/submission/204929369
 */


#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    vector<int> rounds;
 
    while (t--) {
        int n;
        cin >> n;
       
        int power = 1;
        while (n) {
            int digit = n % 10;
            if (digit > 0) {
                rounds.push_back(digit * power);
                 
            }
            n /= 10;
            power *= 10;
        }
        cout << rounds.size() << endl;
        for (auto i : rounds)
            cout << i << ' ';
        cout << endl;
        rounds.clear();
    }
  
   
   
    return 0;
}