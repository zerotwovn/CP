/**
 * Problem: 1760D - Challenging Valleys
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1760/problem/D
 * Rating: 1000
 * Tags: implementation, two pointers
 *
 * Verdict: Accepted
 * Submission ID: 182415688
 * Submission Time: 2022-11-25 02:15:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 77 ms
 * Memory: 1600 KB
 * Codeforces Link: https://codeforces.com/contest/1760/submission/182415688
 */

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
int main(){
	fast
	long long t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		long long a[n+2], temp=1, cnt=0, o=n-1;
		for (long long i=1;i<=n;i++) cin >> a[i];
		a[0]=a[n+1]=1e9+1;
		for (long long i=1;i<=n;i++){
			if (a[i]==a[i+1]){
				if (a[i-1]>a[i]){
					for (long long j=i+1;j<=n;j++){
						if (a[j]==a[j+1]) continue;
						else {
							if (a[j]<a[j+1]){
								cnt++;
							}
								i=j;
								break;
						}
					}
				}
			}
			else if(a[i-1]>a[i] && a[i]<a[i+1]){
				cnt++;
			}
			if (cnt>1) break;
		}
		if (cnt==1 || n==1) cout << "YES" << endl;
		else cout <<"NO" << endl;
	}
}
