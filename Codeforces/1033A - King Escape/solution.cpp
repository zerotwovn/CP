/**
 * Problem: 1033A - King Escape
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1033/problem/A
 * Rating: 1000
 * Tags: dfs and similar, graphs, implementation
 *
 * Verdict: Accepted
 * Submission ID: 177942212
 * Submission Time: 2022-10-26 03:28:35 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/1033/submission/177942212
 */

#include<iostream>

using namespace std;

 
int main()
{
    long long n;
    cin>>n;
    long long a,b,h,k,x,y;
    cin>>a>>b; cin>>h>>k; cin>>x>>y;
    if((h > a && x < a) || (h < a && x > a) || (k > b && y < b) || (k < b && y > b)){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;
    }
}
