#include<bits/stdc++.h>
using namespace std;
int a[100], n, s; // numbers to use, size of array, number of numbers you can use, sum to produce
bool partsum(int i = 0, int sum = 0) {
    if (i == n) return sum == s;
    if (partsum(i + 1, sum + a[i])) {
        cout << a[i] << ' ';
        if (i == 0 && sum == 0) cout << endl;
        return 1;
    } else if (partsum(i + 1, sum)) {
        return 1;
    }
    return 0;
}
bool partsum_dp() {
    bool dp[n][s];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < s; j++) {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
        }
    }
    return dp[n - 1][s - 1];
}
bool partsum_boolarr() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    if (s > sum) return 0;
    bool f[s + 1];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = s; j >= 0; j--) {
            if (f[j] && j + a[i] <= s) {
                f[j + a[i]] = 1;
            }
        }
    }
    return f[s];
}
int main() {
    freopen("partsum.in", "r", stdin);
    freopen("partsum.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << (bool)partsum_boolarr() << endl;
}