/**
 * Problem: 381A - Sereja and Dima
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/381/problem/A
 * Rating: 800
 * Tags: greedy, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 173763752
 * Submission Time: 2022-09-28 00:49:14 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/381/submission/173763752
 */


#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long a[n],l=0,r=n-1;;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0]<<" "<<0;
        return 0;
    }
    long long se=0,di=0,dem=0;
    while(l<=r){
        if(a[l]>a[r]){
            if(dem==0)
                se+=a[l];
            else
                di+=a[l];
            l++;
        }else{
            if(a[l]<a[r]){
                if(dem==0)
                    se+=a[r];
                else
                    di+=a[r];
                r--;
            }
        }
        if(dem==0)
            dem=1;
        else
            dem=0;
        if(l==r){
            if(dem==0)
                se+=a[l];
            else
                di+=a[l];
            l++;
        }
    }
    cout<<se<<" "<<di;
    return 0;
}