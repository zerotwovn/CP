/**
 * Problem: 631E - Product Sum
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/631/problem/E
 * Rating: 2600
 * Tags: data structures, dp, geometry
 *
 * Verdict: Wrong Answer
 * Submission ID: 256862449
 * Submission Time: 2024-04-16 03:26:42 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 46 ms
 * Memory: 6300 KB
 * Link: https://codeforces.com/contest/631/submission/256862449
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

ll a[N], sum[N], dp[N], dp2[N];
int n;

ll characteristic(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    // Forward pass
    for (int i = 1; i <= n; ++i) {
        dp[i] = characteristic(1, i) - a[i];
        dp[i] = max(dp[i], dp[i - 1]);
    }

    // Backward pass
    ll ans = dp[n];
    for (int i = n; i >= 1; --i) {
        dp2[i] = characteristic(i, n) - a[i];
        if (i < n) dp2[i] = max(dp2[i], dp2[i + 1]);
        if (i > 1) ans = max(ans, dp[i - 1] + dp2[i]);
    }

    cout << ans << endl;

    return 0;
}
