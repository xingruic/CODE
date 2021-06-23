#include<bits/stdc++.h>
using namespace std;
int main() {
    int T, M; // T=alotted time for picking
              // M=no. of plants
    cin >> T >> M;
    int time[M + 1], val[M + 1];
    for (int i = 1; i <= M; i++) {
        cin >> time[i] >> val[i];
    }
    int dp[M + 1][T + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= T; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= time[i]) {
                // cout << j << ">=" << time[i] << ' ';
                dp[i][j] = max(dp[i - 1][j - time[i]] + val[i], dp[i][j]);
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    // for (int i = 0; i <= M; i++) {
    //     for (int j = 0; j <= T; j++) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    cout << dp[M][T] << endl;
}