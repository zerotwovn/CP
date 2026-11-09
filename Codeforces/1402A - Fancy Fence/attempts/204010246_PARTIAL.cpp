/**
 * Problem: 1402A - Fancy Fence
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1402/problem/A
 * Rating: 1800
 * Tags: *special, data structures, dsu, implementation, math, sortings
 *
 * Verdict: Partial
 * Submission ID: 204010246
 * Submission Time: 2023-04-30 07:13:43 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 1000 ms
 * Memory: 262100 KB
 * Link: https://codeforces.com/contest/1402/submission/204010246
 */

 #include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        vector<long long> h(n),w(n);
        
        // Reading input values
        for(int i=0;i<n;i++)
            cin>>h[i];
        for(int i=0;i<n;i++)
            cin>>w[i];
        
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            // Counting number of fancy rectangles on single section of fence
            ans = (ans + (h[i] * w[i]) % mod) % mod;
        }

        stack<pair<long long, long long>> s;
        for(int i=0;i<n;i++)
        {
            long long len = w[i];
            
            // Removing top elements of stack having height >= current section's height
            while(!s.empty() && s.top().first>=h[i])
            {
                len = min(len,s.top().second);
                ans = (ans + s.top().first * len % mod * (i-s.top().second) % mod) % mod;
                s.pop();
            }
            
            if(!s.empty())
            {
                len = min(len,s.top().second);
                ans = (ans + s.top().first * len % mod * (i-1-s.top().second+1) % mod) % mod;
            }
            
            s.push(make_pair(h[i],i));
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
