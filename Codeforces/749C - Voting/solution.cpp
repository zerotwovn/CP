/**
 * Problem: 749C - Voting
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/749/problem/C
 * Rating: 1500
 * Tags: greedy, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174062779
 * Submission Time: 2022-09-30 09:35:44 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 62 ms
 * Memory: 2100 KB
 * Codeforces Link: https://codeforces.com/contest/749/submission/174062779
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin>>n;
    char a[n];
    queue<int> d,r;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='D') d.push(i);
        else r.push(i);
    }
    if(r.empty()){
        cout<<"D";
        return 0;
    }
    else if(d.empty()){
        cout<<"R";
        return 0;
    }
    while(true){
        if(d.front()<r.front()){
            r.pop();
            d.push(d.front()+n);
            d.pop();
        }
        else{
            d.pop();
            r.push(r.front()+n);
            r.pop();
        }
        if(r.empty()){
            cout<<"D";
            return 0;
        }
        else if(d.empty()){
            cout<<"R";
            return 0;
        }
    }
}
