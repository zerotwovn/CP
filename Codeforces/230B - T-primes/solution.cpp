/**
 * Problem: 230B - T-primes
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/230/problem/B
 * Rating: 1300
 * Tags: binary search, implementation, math, number theory
 *
 * Verdict: Accepted
 * Submission ID: 204928807
 * Submission Time: 2023-05-07 05:55:55 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 808 ms
 * Memory: 49700 KB
 * Codeforces Link: https://codeforces.com/contest/230/submission/204928807
 */

#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int A[N+1];
bool is_prime[10000001];
void sangEratosthenes()
{
    is_prime[0]=is_prime[1]=true;
    for (long long i = 2; i*i < N; ++i)
        if (!is_prime[i])
        for (long long j=i*i; j<= N; j+=i)
            is_prime[j] = true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sangEratosthenes();
    long long n;
    cin>>n;
    long long a[n+1];
    for (long long i=1;i<=n;i++)
        cin>>a[i];
    for (long long i=1;i<=n;i++)
    {
        long double kq=sqrt(a[i]);
        if (kq==(long long)kq)
        {
            if (is_prime[(long long)kq])
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        if (kq!=(long long)kq)
            cout<<"NO"<<endl;
    }
 
    return 0;
}
