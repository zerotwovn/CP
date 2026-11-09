/**
 * Problem: 609E - Minimum spanning tree for each edge
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/609/problem/E
 * Rating: 2100
 * Tags: data structures, dfs and similar, dsu, graphs, trees
 *
 * Verdict: Runtime Error
 * Submission ID: 233929657
 * Submission Time: 2023-11-23 14:28:14 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 0 ms
 * Memory: 37600 KB
 * Link: https://codeforces.com/contest/609/submission/233929657
 */

#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e18;
const int MAXN = 2e5 + 10;

struct DATA {
    int u, v, w, id;
    bool operator < (const DATA &A) {
        return w < A.w;
    }
};

vector<DATA> H;

struct DSU {
    int p[MAXN], sz[MAXN];

    void Build() {
        for (int i = 1; i <= MAXN; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int Find(int v) {
        return ((p[v] == v) ? v : (p[v] = Find(p[v])));
    }

    bool Union(int u, int v) {
        u = Find(u), v = Find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        return true;
    }
} Dsu;

vector<pair<int, int>> G[MAXN];
int root = -1;

int d[MAXN], p[MAXN][20], maxx[MAXN][20];

void dfs(int u, int pre, int dist) {
    p[u][0] = pre;
    maxx[u][0] = dist;
    for (int k = 1; k <= 18; ++k) {
        p[u][k] = p[p[u][k - 1]][k - 1];
        maxx[u][k] = max(maxx[u][k - 1], maxx[p[u][k - 1]][k - 1]);
    }
    for (auto& e : G[u]) {
        int v = e.first, uv = e.second;
        if (v == pre) continue;
        d[v] = d[u] + 1;
        dfs(v, u, uv);
    }
}

int LCA(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int res = -oo;
    for (int k = 18; k >= 0; --k) {
        if (d[p[u][k]] >= d[v]) {
            res = max(res, maxx[u][k]);
            u = p[u][k];
        }
    }

    if (u == v) return res;

    for (int k = 18; k >= 0; --k) {
        if (p[u][k] != p[v][k]) {
            res = max(res, maxx[u][k]);
            res = max(res, maxx[v][k]);
            u = p[u][k];
            v = p[v][k];
        }
    }
    res = max(res, maxx[u][0]);
    res = max(res, maxx[v][0]);
    return res;
}

int check[MAXN], res[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        H.push_back({u, v, w, i});
    }

    Dsu.Build();
    sort(H.begin(), H.end());
    int ans = 0;

    for (auto& e : H) {
        int u = e.u, v = e.v, w = e.w, id = e.id;
        if (Dsu.Union(u, v)) {
            ans += w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
            if (root == -1) root = u;
            check[id] = 1;
        }
    }

    dfs(root, root, 0);

    for (auto& e : H) {
        int u = e.u, v = e.v, w = e.w, id = e.id;
        if (check[id] == 1) {
            res[id] = ans;
            continue;
        }
        res[id] = ans - LCA(u, v) + w;
    }

    for (int i = 1; i <= M; ++i) cout << res[i] << '\n';

    return 0;
}
