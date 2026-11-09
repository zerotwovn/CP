/**
 * Problem: 337A - Puzzles
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/337/problem/A
 * Rating: 900
 * Tags: greedy
 *
 * Verdict: Accepted
 * Submission ID: 204927648
 * Submission Time: 2023-05-07 05:47:23 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/337/submission/204927648
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int last = n-1,Max=INT_MAX;
    for(int i=0;i<v.size()-n+1;i++,last++){
        if((v[last]-v[i])<Max){
            Max=v[last]-v[i];
        }
    }
    cout << Max << std::endl;
    return 0;
}