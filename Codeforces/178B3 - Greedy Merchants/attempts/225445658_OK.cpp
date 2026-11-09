/**
 * Problem: 178B3 - Greedy Merchants
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/178/problem/B3
 * Rating: 1800
 * Tags: 
 *
 * Verdict: Accepted
 * Submission ID: 225445658
 * Submission Time: 2023-09-27 01:02:52 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 466 ms
 * Memory: 22800 KB
 * Link: https://codeforces.com/contest/178/submission/225445658
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
int n, m, k, dfn[N], low[N], ebc[N], cnt, sum, lg[N], d[N], f[20][N];
vector<int> g[N], e[N];
stack<int> s;
bool is[N];
void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++cnt;
    s.push(x);
    is[x] = 1;
    for (int i : g[x]) {
        if (i != fa) {
            if (!dfn[i]) {
                tarjan(i, x);
                low[x] = min(low[x], low[i]);
            } else if (is[i]) {
                low[x] = min(low[x], dfn[i]);
            }
        }
    }
    if (dfn[x] == low[x]) {
        ++sum;
        while (1) {
            int p = s.top();
            s.pop();
            is[p] = 0;
            ebc[p] = sum;
            if (x == p) {
                break;
            }
        }
    }
}
void dfs(int x, int fa) {
    if (fa) {
        d[x] = d[fa] + 1;
        f[0][x] = fa;
        for (int i = 1; i <= lg[d[x]]; i++) {
            f[i][x] = f[i - 1][f[i - 1][x]];
        }
    }
    for (int i : e[x]) {
        if (i != fa) {
            dfs(i, x);
        }
    }
}
inline int lca(int x, int y) {
    if (d[x] < d[y]) {
        swap(x, y);
    }
    while (d[x] > d[y]) {
        x = f[lg[d[x] - d[y]]][x];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg[d[x]]; i >= 0; i--) {
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    }
    return f[0][x];
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tarjan(1, 0);
    for (int i = 1; i <= n; i++) {
        lg[i] = log2(i);
        for (int j : g[i]) {
            if (ebc[i] < ebc[j]) {
                e[ebc[i]].push_back(ebc[j]);
                e[ebc[j]].push_back(ebc[i]);
            }
        }
    }
    dfs(1, 0);
    cin >> k;
    for (int i = 1, u, v, q; i <= k; i++) {
        cin >> u >> v;
        if (ebc[u] == ebc[v]) {
            cout << "0\n";
            continue;
        }
        q = lca(ebc[u], ebc[v]);
        cout << d[ebc[u]] + d[ebc[v]] - (d[q] << 1) << '\n';
    }
    return 0;
}
