/**
 * Problem: 1387B2 - Village (Maximum)
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1387/problem/B2
 * Rating: 2500
 * Tags: *special, dfs and similar, trees
 *
 * Verdict: Accepted
 * Submission ID: 226449409
 * Submission Time: 2023-10-03 14:20:18 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 108 ms
 * Memory: 13600 KB
 * Link: https://codeforces.com/contest/1387/submission/226449409
 */

#include    <bits/stdc++.h>

using namespace std;
 
const long long N = 1e5 + 55;
 
long long n;
long long ret = 0;
long long subTree[N], ans[N];
vector<long long> ord, edges[N];
 
void dfs(long long u, long long p)
{
    subTree[u] = 1;
    ord.push_back(u);
    for(long long v : edges[u])
    {
        if (v == p) continue;
        dfs(v, u);
        subTree[u] += subTree[v];
        ret += min(subTree[v], n - subTree[v]);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(long long i=0; i<n-1; i++)
    {
        long long u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    dfs(0, -1);
    for(long long i=0; i<n; i++)
    {
        long long u = ord[i], v = ord[(i + n / 2) % n];
        ans[v]= u;
    }                       
    cout << ret * 2 << endl;
    for(long long i=0; i<n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}//https://codeforces.com/problemset/problem/1387/B2
