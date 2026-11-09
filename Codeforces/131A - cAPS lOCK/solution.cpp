/**
 * Problem: 131A - cAPS lOCK
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/131/problem/A
 * Rating: 1000
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 186982801
 * Submission Time: 2022-12-28 01:19:55 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 15 ms
 * Memory: 0 KB
 * Link: https://codeforces.com/contest/131/submission/186982801
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;cin>>s;
    int n=s.size();
    bool kiemtra=false;
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(isupper(s[i]))
            dem++;
    }
    if(dem==n)
        kiemtra=true;
    else if(dem==n-1&&islower(s[0]))
        kiemtra=true;
    if(!kiemtra)
        cout<<s<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(islower(s[i]))
                s[i]=toupper(s[i]);
            else
                s[i]=tolower(s[i]);
        }
        cout<<s<<endl;
    }
    return 0;
}