#include<bits/stdc++.h>
using namespace std;
int k, n;
int a[10][20];
bool cons[21][21];
int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> k >> n;
    for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) {
        cin >> a[i][j];
    }
    memset(cons, 1, sizeof(cons));
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            for (int l = j - 1; l >= 0; l--)
                cons[a[i][l]][a[i][j]] = 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (cons[i][j]) cnt++;
        }
    }
    cout << cnt << endl;
}