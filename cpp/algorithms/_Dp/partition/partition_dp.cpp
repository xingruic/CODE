#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k; // number, parts
    cin >> n >> k;
    int t = clock();
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j > i) dp[i][j] = dp[i][i];
            else {
                dp[i][j] = 1;
                for (int k = 2; k <= j; k++) {
                    int ts = dp[i][j];
                    if (i - k < 0) continue;
                    dp[i][j] += dp[i - k][k];
                    // cout << i - k << ' ' << k << ' ' << dp[i][j] - ts << endl;
                }
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    cout << dp[n][k] << endl;
    cout << "Done in " << (clock() - t) * 1.0 / CLOCKS_PER_SEC << 's' << endl;
}