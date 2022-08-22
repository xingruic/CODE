#include<bits/stdc++.h>
using namespace std;
int n, m, p;
bool a[5001][5001];
bool ask[5001][5001];
int main() {
    memset(a, 0, sizeof(a));
    memset(ask, 0, sizeof(ask));
    cin >> n >> m >> p;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int j = 1; j <= p; j++) {
        cin >> x >> y;
        ask[x][y] = 1;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                if (a[i][j] && a[j][k]) a[i][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ask[i][j]) cout << (a[i][j] ? "Yes" : "No") << endl;
        }
    }
}