/**
 * Problem: 609E - Minimum spanning tree for each edge
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/609/problem/E
 * Rating: 2100
 * Tags: data structures, dfs and similar, dsu, graphs, trees
 *
 * Verdict: Accepted
 * Submission ID: 233930563
 * Submission Time: 2023-11-23 14:35:52 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 436 ms
 * Memory: 57200 KB
 * Link: https://codeforces.com/contest/609/submission/233930563
 */

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &p) const {
        return p.w > w;
    }
};

const int N = 2e5 + 9;
int m, n;
ll w_mst;
vector<Edge> edges;
vector<pair<int, int>> g[N];
Edge queries[N];

struct DSU {
    int par[N], sz[N], n;

    void init(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i) par[i] = i, sz[i] = 1;
    }

    int findroot(int v) {
        return par[v] == v ? v : par[v] = findroot(par[v]);
    }

    bool unite(int u, int v) {
        int a = findroot(u), b = findroot(v);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        return 1;
    }
};

void kruskal() {
    DSU dsu;
    dsu.init(n + 4);
    for (auto t : edges) {
        int u = t.u, v = t.v, w = t.w;
        if (dsu.unite(u, v)) {
            w_mst += 1LL * w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
}

int up[N][20], mx[N][20], h[N];

void dfs(int u) {
    for (auto it : g[u])
        if (it.first != up[u][0]) {
            int v = it.first, w = it.second;
            up[v][0] = u;
            h[v] = h[u] + 1;
            mx[v][0] = w;
            for (int j = 1; j < 18; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];
                mx[v][j] = max(mx[v][j - 1], mx[up[v][j - 1]][j - 1]);
            }
            dfs(v);
        }
}

ll lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v], res = 0;
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) {
            res = max(res, mx[u][j]);
            u = up[u][j];
        }
    if (u == v) return res;
    k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) {
            res = max(res, mx[u][j]);
            res = max(res, mx[v][j]);
            u = up[u][j];
            v = up[v][j];
        }
    res = max(res, mx[u][0]);
    res = max(res, mx[v][0]);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
        queries[i] = {x, y, w};
    }
    sort(edges.begin(), edges.end());
    kruskal();
    dfs(1);
    for (int i = 1; i <= m; ++i) {
        Edge it = queries[i];
        int u = it.u, v = it.v, w = it.w;
        cout << w_mst + 1LL * w - lca(u, v) << '\n';
    }
    return 0;
}
