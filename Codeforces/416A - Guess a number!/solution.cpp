/**
 * Problem: 416A - Guess a number!
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/416/problem/A
 * Rating: 1400
 * Tags: greedy, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174060114
 * Submission Time: 2022-09-30 09:06:46 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/416/submission/174060114
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin>>n;
    int x=-2000000000,y=2000000000;
    while(n--){
        string a;
        char b;
        int num=0;
        cin>>a>>num>>b;
        if(b=='Y'){
            if(a==">") x=max(x,num+1);
            else if(a==">=") x=max(x,num);
            else if(a=="<") y=min(y,num-1);
            else if(a=="<=") y=min(y,num);
        }
        else{
            if(a==">") y=min(y,num);
            else if(a==">=") y=min(y,num-1);
            else if(a=="<") x=max(x,num);
            else if(a=="<=") x=max(x,num+1);
        }
    }
    if(y>=x) cout<<x;
    else cout<<"Impossible";
}
