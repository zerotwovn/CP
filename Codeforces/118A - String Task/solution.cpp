/**
 * Problem: 118A - String Task
 * Contest: Codeforces
 * URL: https://codeforces.com/contest/118/problem/A
 * Rating: 1000
 * Tags: implementation, strings
 *
 * Verdict: Accepted
 * Submission ID: 184336509
 * Submission Time: 2022-12-08 13:41:56 UTC
 * Language: C++17 (GCC 7-32)
 * Time: 30 ms
 * Memory: 0 KB
 * Codeforces Link: https://codeforces.com/contest/118/submission/184336509
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std; 
 
int main() {
    char s[101], s2[101];
    char s1[] = "aeiouy";
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] < 97)
            s[i] = s[i]+32;
    }
    int flag = 0;
 
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strlen(s1); j++) {
            if (s[i] == s1[j]) {
                flag = 1;
                break;
            }
 
        } 
        if (flag == 0) {
            cout << "." << s[i];
        }
        flag = 0;
    }
    cout << endl;
 
 
    return 0;
}
