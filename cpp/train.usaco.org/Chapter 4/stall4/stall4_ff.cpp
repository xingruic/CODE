/*
ID:xingrui1
TASK:stall4
LANG:C++14
*/

/***************************
 stall4 using ford-fulkerson
 ***************************/

#include<bits/stdc++.h>
using namespace std;
int n, m;
bool used[201];
bool stall[201][201];
bool cs[201][201]; // adjacency matrix for cows -> stalls
bool c[201]; // adjacency matrix from imaginary source -> cows
bool s[201]; // adjacency matrix from stalls -> imaginary sink
int main() {
    memset(stall, 0, sizeof(stall));
    memset(s, 0, sizeof(s));
    memset(c, 0, sizeof(c));
    memset(cs, 0, sizeof(cs));
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    cin >> n >> m;
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++) {
            cin >> t;
            stall[i][t] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        a[0][i] = 1;
        a[i + 200][402] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (stall[i][j]) {

            }
        }
    }
}