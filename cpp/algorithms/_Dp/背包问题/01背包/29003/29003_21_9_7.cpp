#include<bits/stdc++.h>
using namespace std;
int n, m; // n=time, m=number of species
int t[105], v[105];
int main() {
    freopen("29003.in", "r", stdin);
    freopen("29003.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i] >> v[i];
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < t[i])
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    cout << dp[m][n] << endl;
}