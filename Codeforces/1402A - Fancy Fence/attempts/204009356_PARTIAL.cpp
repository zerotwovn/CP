/**
 * Problem: 1402A - Fancy Fence
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1402/problem/A
 * Rating: 1800
 * Tags: *special, data structures, dsu, implementation, math, sortings
 *
 * Verdict: Partial
 * Submission ID: 204009356
 * Submission Time: 2023-04-30 07:02:14 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1000 ms
 * Memory: 1600 KB
 * Link: https://codeforces.com/contest/1402/submission/204009356
 */

 #include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n,h[100005],w[100005],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        long long len=w[i];
        ans=(ans+len*h[i]%mod)%mod; // sum up all the fancy rectangles on a single section
        for(int j=i+1;j<=n&&h[j]>=h[i];j++) len=min(len,w[j]),ans=(ans+len*h[i]%mod)%mod; // calculate the fancy rectangles between two sections
        for(int j=i-1;j>=1&&h[j]>=h[i];j--) len=min(len,w[j]),ans=(ans+len*h[i]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
