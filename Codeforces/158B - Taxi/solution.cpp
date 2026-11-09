/**
 * Problem: 158B - Taxi
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/158/problem/B
 * Rating: 1100
 * Tags: *special, greedy, implementation
 *
 * Verdict: Accepted
 * Submission ID: 186413402
 * Submission Time: 2022-12-23 02:20:19 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 156 ms
 * Memory: 400 KB
 * Codeforces Link: https://codeforces.com/contest/158/submission/186413402
 */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,s1=0,s2=0,s3=0,taxi=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
 
    for(i=0;i<n;i++)
    {
        if(arr[i]==4)
        taxi++;
        else if(arr[i]==3)
        s3++;
        else if(arr[i]==2)
        s2++;
        else 
        s1++;
    }
     if(s1>=s3)
     {
            taxi+=s3;
             s1=s1-s3;
             s3=0;
     }
            else{
                taxi+=s1;
              s3=s3-s1;
              s1=0;}
       if(s3>0)
       {taxi=taxi+s3;
       s3=0;}  
 
       if(s2>0)
       {
        taxi=taxi+s2/2;
        s2=s2%2;
       } 
 
    s1=s1+2*s2; 
     if(s1<=4 && s1>0)
     taxi++;
     else if(s1%4!=0)
      taxi+=(s1/4)+1;
      else
      taxi+=s1/4;
 
 
    cout<<taxi;
}
