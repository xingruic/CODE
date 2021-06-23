#include<bits/stdc++.h>
using namespace std;
int main() {
    int v, n;
    cin >> v >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1][v + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = v;
    }
    for (int j = 0; j <= v; j++) {
        dp[0][j] = v;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] - a[i]);
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    cout << dp[n][v] << endl;
}