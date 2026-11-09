/**
 * Problem: 489C - Given Length and Sum of Digits...
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/489/problem/C
 * Rating: 1400
 * Tags: dp, greedy, implementation
 *
 * Verdict: Accepted
 * Submission ID: 174033460
 * Submission Time: 2022-09-30 01:58:46 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/489/submission/174033460
 */

#include <bits/stdc++.h>
 
using namespace std;
 
int main ()
{
  int t=1;
  while (t--)
  {
    double n, m;
    cin >>n>>m;
    double x=ceil (m/9);
    int y=fmod (m,9);
    
    if (n==1&&m==0)
    cout <<0<<" "<<0;
    
    else if (n<ceil(x)||m==0)
    cout <<-1<<" "<<-1;
    
    else
    {
      if (n==x && y==0)
      {
        for (int i=0;i<n;i++)
        {cout <<9;}
        cout <<" ";
        for (int i=0;i<n;i++)
        {cout <<9;}
      }
      else if (n>x && y==0)             
      {
        cout <<1;
        for (int i=0;i<n-x-1;i++)
        {cout <<y;}
        cout <<8;
        for (int i=0;i<x-1;i++)
        {cout <<9;}
        cout <<" ";
        for (int i=0;i<x;i++)
        {cout <<9;}
        for (int i=0;i<n-x;i++)
        {cout <<y;}
      }
      else
      {
        if (n==x)
        {
          cout <<y;
          for (int i=0;i<n-1;i++)
          {cout <<9;}
          cout <<" ";
          for (int i=0;i<n-1;i++)
          {cout <<9;}
          cout <<y;
        }
        else
        {
          cout <<1;
          for (int i=0;i<n-x-1;i++)
          {cout <<0;}
          cout <<y-1;
          for (int i=0;i<x-1;i++)
          {cout <<9;}
          cout <<" ";
          for (int i=0;i<x-1;i++)
          {cout <<9;}
          cout <<y;
          for (int i=0;i<n-x;i++)
          {cout <<0;}
        }
      }
    }
  }
  
  
  return 0;
}
