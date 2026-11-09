/**
 * Problem: 978C - Letters
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/978/problem/C
 * Rating: 1000
 * Tags: binary search, implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 174061303
 * Submission Time: 2022-09-30 09:19:29 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 249 ms
 * Memory: 3100 KB
 * Codeforces Link: https://codeforces.com/contest/978/submission/174061303
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

typedef vector<ll> vl;
 
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vl a(n), pref(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    pref[0] = a[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i-1] + a[i];
    for(int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        ll l = 0, r = n - 1;
        while(l < r)
        {
            ll mid = (l + r) / 2;
            if(pref[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        cout << r + 1 << " " << x - (r - 1 >= 0 ? pref[r-1] : 0) << '\n';
    }
}
