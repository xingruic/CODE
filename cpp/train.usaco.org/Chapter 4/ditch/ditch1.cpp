/*
TASK:ditch
ID:xingrui1
LANG:C++11
*/
#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[201], e[201], c[201]; // s, e, and c, idk if i'm gonna use
int a[301][301]; // adjacency matrix
bool been[301]; // array for recursion, whether we've been to this point or not (to prevent loops)
int ans = 0;
void find(int x = 1, int cap = 0x7fffffff) { // ford-fulkerson
    if (x == m) {
        ans += cap;
        int previ = 1;
        for (int i = 2; i <= m; i++) {
            if (been[i]) {
                a[previ][i] -= cap;
                a[i][previ] += cap;
                previ = i;
            }
        }
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (a[x][i] && !been[i]) { // if we can go there and we haven't been there yet
            been[i] = 1; // set this been to 1 for recursion
            find(i, min(cap, a[x][i]));
            been[i] = 0; // unset been for recursion
        }
    }
}
int main() {
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    memset(a, 0, sizeof(a));
    memset(been, 0, sizeof(been));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> c[i];
        a[s[i]][e[i]] += c[i]; // if 2 channels exist this way just combine them instead of creating another one
    }
    been[1] = 1;
    find();
    cout << ans << endl;
}