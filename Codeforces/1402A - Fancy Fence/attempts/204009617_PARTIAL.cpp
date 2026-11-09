/**
 * Problem: 1402A - Fancy Fence
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1402/problem/A
 * Rating: 1800
 * Tags: *special, data structures, dsu, implementation, math, sortings
 *
 * Verdict: Partial
 * Submission ID: 204009617
 * Submission Time: 2023-04-30 07:05:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 374 ms
 * Memory: 3500 KB
 * Link: https://codeforces.com/contest/1402/submission/204009617
 */

 #include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n,h[100005],w[100005],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    stack<pair<long long, long long>> s; // stores (height, width) pairs of sections that are higher than the current section
    for(int i=1;i<=n;i++){
        long long len=w[i];
        ans=(ans+len*h[i]%mod)%mod; // sum up all the fancy rectangles on a single section
        while(!s.empty() && s.top().first>=h[i]){
            len=min(len,s.top().second);
            ans=(ans+s.top().first*len%mod*(i-s.top().second)%mod)%mod; // calculate number of fancy rectangles between the current section and each section in the stack
            s.pop();
        }
        if(!s.empty()) ans=(ans+s.top().first*len%mod*((i-1)-s.top().second+1)%mod)%mod; // calculate number of fancy rectangles between the current section and the previous section in the stack
        s.push(make_pair(h[i],i));
    }
    cout<<ans<<endl;
    return 0;
}
