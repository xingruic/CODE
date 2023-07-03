#include<bits/stdc++.h>
using namespace std;
int n, m;
bool a[101][101];
int out[101] = { 1 };
int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    memset(a, 0, sizeof(a));
    {
        cin >> n >> m;
        int x, y;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            a[x][y] = a[y][x] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        int _max = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == _max + 1) _max = a[i][j];
        }
        out[i] = _max + 1;
        cout << out[i];
    }
    cout << endl;
}