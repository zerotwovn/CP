/**
 * Problem: 277A - Learning Languages
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/277/problem/A
 * Rating: 1400
 * Tags: dfs and similar, dsu
 *
 * Verdict: Accepted
 * Submission ID: 238587728
 * Submission Time: 2023-12-23 17:38:23 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 1100 KB
 * Codeforces Link: https://codeforces.com/contest/277/submission/238587728
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 101;
const int maxm = 101;

int cnt[maxm];
int peo[maxm][maxn];
int pre[maxn];
int n, m;

void init()
{
    int i;
    for (i = 1; i <= n; i++)
        pre[i] = i;
}

int find(int x)
{
    int r = x;
    while (r != pre[r])
        r = pre[r];
    int i = x, j;
    while (i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void unon(int a, int b)
{
    int at = find(a);
    int bt = find(b);
    if (at == bt)
        return;
    else
    {
        pre[at] = pre[bt];
    }
}

int main()
{
    int k, v;
    while (cin >> n >> m)
    {
        memset(peo, 0, sizeof(peo));
        memset(cnt, 0, sizeof(cnt));
        init();
        bool f = false;
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            if (k)
                f = true;
            while (k--)
            {
                cin >> v;
                peo[v][cnt[v]++] = i;
            }
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1, u = peo[i][0]; j < cnt[i]; j++)
                unon(peo[i][j], u);
        int res = -1;
        for (int i = 1; i <= n; i++)
            if (pre[i] == i)
                res++;
        if (f)
            cout << res << endl;
        else
            cout << res + 1 << endl;
    }
    return 0;
}
