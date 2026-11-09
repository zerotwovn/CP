/**
 * Problem: 86D - Powerful array
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/86/problem/D
 * Rating: 2200
 * Tags: data structures, implementation, math, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 238616446
 * Submission Time: 2023-12-24 03:14:44 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 4740 ms
 * Memory: 9700 KB
 * Link: https://codeforces.com/contest/86/submission/238616446
 */

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

#define ll long long
#define ld long double

const int block = 250;

array<int, 3> queries[200005];
int A[200005], cnt[1000005];
ll answer[200005];
ll res = 0;

bool cmp(const array<int, 3> &a, const array<int, 3> &b){
    if(a[0] / block != b[0] / block){
        return a[0] < b[0];
    }
    return (a[0] / block % 2 ? a[1] > b[1] : a[1] < b[1]);
}

void add(int pos){
    cnt[A[pos]]++;
    ll cur = cnt[A[pos]];
    res -= (cur - 1) * (cur - 1) * (ll)A[pos];
    res += cur * cur * (ll)A[pos];
}

void rem(int pos){
    cnt[A[pos]]--;
    ll cur = cnt[A[pos]];
    res -= (cur + 1) * (cur + 1) * (ll)A[pos];
    res += cur * cur * (ll)A[pos];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N >> Q;

    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    for(int i = 1; i <= Q; ++i){
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }

    sort(queries + 1, queries + Q + 1, cmp);

    int curL = 1, curR = 0;
    for(int i = 1; i <= Q; ++i){
        int L = queries[i][0], R = queries[i][1];

        while(curL > L){
            curL--;
            add(curL);
        }
        while(curR < R){
            curR++;
            add(curR);
        }
        while(curL < L){
            rem(curL);
            curL++;
        }
        while(curR > R){
            rem(curR);
            curR--;
        }

        answer[queries[i][2]] = res;
    }

    for(int i = 1; i <= Q; ++i){
        cout << answer[i] << "\n";
    }

    return 0;
}
