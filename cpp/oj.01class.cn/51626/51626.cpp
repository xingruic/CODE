#include<bits/stdc++.h>
using namespace std;
int n, m;
int x[1001], y[1001];
double a[1001][1001]; // stores the SQUARE of the distance btwn 2 points
bool road[1001][1001];
bool inc[1001]; // whether or not this point is included in mst
void fillinc(int x) {
    if (inc[x]) return;
    inc[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (road[x][i] && !inc[i]) {
            fillinc(i);
        }
    }
    return;
}
int main() {
    /********************************************************************/
    freopen("cases/4.out", "r", stdin); // 4th test case still not passed
    /********************************************************************/
    memset(road, 0, sizeof(road));
    memset(a, 0, sizeof(a));
    memset(x, -1, sizeof(x));
    memset(y, -1, sizeof(y));
    memset(inc, 0, sizeof(inc));
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        int u, v;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            road[u][v] = road[v][u] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            a[i][j] = a[j][i] = sqrt((long long)(x[i] - x[j]) * (long long)(x[i] - x[j]) + (long long)(y[i] - y[j]) * (long long)(y[i] - y[j]));
            // cout << a[i][j] << ' ';
            assert(a[i][j] >= 0);
        }
    }
    int cnt;
    inc[1] = 1;
    double _min;
    int min_j;
    double sum = 0;
    while (cnt < n) {
        _min = 0x7fffffffffffffff;
        for (int i = 1; i <= n; i++) {
            if (inc[i]) {
                for (int j = 1; j <= n; j++) {
                    if (road[i][j] && !inc[j]) {
                        fillinc(j);
                    }
                }
                for (int j = 1; j <= n; j++) {
                    if (!inc[j]) {
                        if (a[i][j] < _min) {
                            // cout << a[i][j] << endl;
                            _min = a[i][j];
                            min_j = j;
                        }
                    }
                }
            }
        }
        sum += _min;
        // cout << _min << ' ';
        // cout << sum << endl;
        inc[min_j] = 1;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (inc[i]) cnt++;
        }
    }
    printf("%.2f\n", sum);
}