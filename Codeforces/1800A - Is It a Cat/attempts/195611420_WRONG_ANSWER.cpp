/**
 * Problem: 1800A - Is It a Cat?
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/1800/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Wrong Answer
 * Submission ID: 195611420
 * Submission Time: 2023-03-02 15:02:09 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/1800/submission/195611420
 */


#include <bits/stdc++.h>

using namespace std;
string chuanhoa (string a) {
    for(int i = 0;i < a.size();i++)
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i]+=32;
    return a;
}
int main()
{
    long long t;
    cin >>t;
    while(t--) {
        long long n;
        cin >> n;
        string a;
        cin >> a;
        string tmp = chuanhoa(a);
        int dem = 0;
        for (int i = 0;i < n;i++)
            if((tmp[i] == 'm' && tmp[i+1] == 'e') || (tmp[i] == 'e' && tmp[i+1] == 'o') || (tmp[i] == 'o' && tmp[i+1] == 'w')) 
                dem++;    
        if(dem >= 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }
    return 0;
}
