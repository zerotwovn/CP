/**
 * Problem: 469A - I Wanna Be the Guy
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/469/problem/A
 * Rating: 800
 * Tags: greedy, implementation
 *
 * Verdict: Accepted
 * Submission ID: 183825559
 * Submission Time: 2022-12-04 11:55:20 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/469/submission/183825559
 */

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long a[1000];
    long long n , p , q;
    cin >> n >> p;
    long long dem = 0;
    for(long long i =  0 ; i < p ; i++){
        cin >> a[i];
    }
    cin >> q;
    for(long long i = p ; i < p + q ; i++){
        cin >> a[i];
    }
    sort(a , a+(p+q));
    for(long long i = 0 ; i < p+q ; i++){
        if(a[i] != a[i+1]){
            dem++;
        }
    }
 
    if(n == dem){
        cout << "I become the guy." <<endl;
    }else{
        cout << "Oh, my keyboard!" << endl;
    }
 
    return 0;
}
