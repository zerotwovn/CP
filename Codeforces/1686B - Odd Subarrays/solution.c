/**
 * Problem: 1686B - Odd Subarrays
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1686/problem/B
 * Rating: 800
 * Tags: dp, greedy
 *
 * Verdict: Compilation Error
 * Submission ID: 168479989
 * Submission Time: 2022-08-16 08:47:38 UTC
 * Language: GNU C11
 * Time: 0 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1686/submission/168479989
 */


#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {int x; cin>>x; v[i] = x;}
        if(n == 1){
            cout<<"0"<<endl; continue;
        }
        int count = 0;
        int i = 1;
        
        while(i < n){
            int j = i;
            while(j < n && v[j] >= v[j-1]) j++;
            if(j >= n) break;
            count++;
            i = j + 2;
        }
        
        cout<<count<<endl;
        
    }
 
    return 0;
}
 