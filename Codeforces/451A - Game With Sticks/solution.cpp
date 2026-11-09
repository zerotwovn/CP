/**
 * Problem: 451A - Game With Sticks
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/451/problem/A
 * Rating: 900
 * Tags: implementation
 *
 * Verdict: Accepted
 * Submission ID: 242005903
 * Submission Time: 2024-01-17 02:02:16 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/451/submission/242005903
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin>>m>>n;
  int a = min(m, n);
  if(a %2 == 0){
    cout<<"Malvika"<<endl;
  }
  else{
    cout<<"Akshat"<<endl;
  }
}