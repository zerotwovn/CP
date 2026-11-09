/**
 * Problem: 732A - Buy a Shovel
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/732/problem/A
 * Rating: 800
 * Tags: brute force, constructive algorithms, implementation, math
 *
 * Verdict: Accepted
 * Submission ID: 214688988
 * Submission Time: 2023-07-21 03:09:54 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/732/submission/214688988
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin>>x>>y;
    int number = 1;
    int res =( x* number)-y;
    int res2 = x*number;
    while((res%10)!=0 && (res2%10)!=0)
    {
        number++;
        res = (x*number)-y;
        res2 = x*number;
    }
    cout<< number<<endl;
}
