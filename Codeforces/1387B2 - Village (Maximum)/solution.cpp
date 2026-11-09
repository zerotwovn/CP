/**
 * Problem: 1387B2 - Village (Maximum)
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1387/problem/B2
 * Rating: 2500
 * Tags: *special, dfs and similar, trees
 *
 * Verdict: Accepted
 * Submission ID: 226399664
 * Submission Time: 2023-10-03 08:38:48 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 93 ms
 * Memory: 8700 KB
 * Codeforces Link: https://codeforces.com/contest/1387/submission/226399664
 */

#include    <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 1e5 + 55;
 
int n;
ll ret = 0;
int subTree[N], ans[N];
vector<int> ord, edges[N];
 
void dfs(int u, int p)
{
    subTree[u] = 1;
    ord.push_back(u);
    for(int v : edges[u])
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
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    dfs(0, -1);
    for(int i=0; i<n; i++)
    {
        int u = ord[i], v = ord[(i + n / 2) % n];
        ans[v]= u;
    }
 
    cout << ret * 2 << endl;
    for(int i=0; i<n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
