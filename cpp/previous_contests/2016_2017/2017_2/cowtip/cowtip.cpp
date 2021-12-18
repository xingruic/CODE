#include<bits/stdc++.h>
using namespace std;
int n;
bool stand[11][11];
bool dp[11][11];
int main() {
    memset(dp, 0, sizeof(dp));
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    memset(stand, 0, sizeof(stand));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> stand[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

        }
    }
}