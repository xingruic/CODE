/*
TASK:butter
ID:xingrui1
LANG:C++14
*/
#include<bits/stdc++.h>
using namespace std;
int n, p, c; // No. of cows, no. of Pastures, no. of Connecting paths
int cow[501]; // pasture that cow is grazing in
int a[801][801]; // adjacency matrix
void floyd() {
    for (int j = 1; j <= p; j++)
        for (int i = 1; i <= p; i++)
            for (int k = 1; k <= p; k++)
                if (a[i][j] + a[j][k] < a[i][k]) a[i][k] = a[k][i] = a[i][j] + a[j][k];
    // for (int i = 1; i <= p; i++) { for (int j = 1; j <= p; j++) cerr << (a[i][j] > 0x3d000000 ? -1 : a[i][j]) << ' ';cerr << endl; }
}
int main() {
    // int t = clock();
    memset(a, 0x3d, sizeof(a));
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    // freopen("butter.err", "w", stderr);
    {
        cin >> n >> p >> c;
        for (int i = 1; i <= n; i++) cin >> cow[i];
        int a, b, x;
        for (int i = 1; i <= c; i++) {
            cin >> a >> b >> x;
            ::a[a][b] = ::a[b][a] = x;
        }
        for (int i = 1; i <= p; i++) ::a[i][i] = 0;
    }
    floyd();
    // floyd();
    int minsum = 0x7fffffff;
    for (int i = 1, j, sum = 0; i <= p; i++, sum = 0) {
        for (j = 1; j <= n; j++) {
            if (a[i][cow[j]] > 0x3d000000) {
                sum = 0x7fffffff;
                break;
            }
            sum += a[i][cow[j]];
            if (sum >= minsum) break;
        }
        // cerr << i << ' ' << sum << endl;
        if (sum < minsum) minsum = sum;
    }
    cout << minsum << endl;
    // cout << (clock() - t) * 1.0 / CLOCKS_PER_SEC << endl;
}