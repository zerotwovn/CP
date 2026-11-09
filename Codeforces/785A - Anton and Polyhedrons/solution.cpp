/**
 * Problem: 785A - Anton and Polyhedrons
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/785/problem/A
 * Rating: 800
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 184102898
 * Submission Time: 2022-12-06 13:34:35 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 390 ms
 * Memory: 4700 KB
 * Link: https://codeforces.com/contest/785/submission/184102898
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "Tetrahedron";
    string b = "Cube";
    string c = "Octahedron";
    string d = "Dodecahedron";
    string e = "Icosahedron";
    long long n;
    cin >>n;
    string arr[n] = {};
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    int s = 0;
    for (int i = 0;i < n;i++) {
        if(arr[i] == a)
            s+=4;
        else if(arr[i] == b)
            s+=6;
        else if(arr[i] == c)
            s+=8;
        else if(arr[i] == d)
            s+=12;
        else 
            s+=20;
    }
    cout << s;
    return 0;
}
