#include<bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;
int m;
int monke[501];
int n;
int x[1001], y[1001];
int a[1001][1001]; // stores the number of units between each point SQUARED
bool inmst[1001]; // whether this node is in the mst yet
bool sel[1001][1001]; // whether this road is selected in the mst
int main() {
    freopen("2.in", "r", stdin);
    memset(monke, -1, sizeof(monke));
    memset(x, inf, sizeof(x));
    memset(a, 0, sizeof(a));
    memset(inmst, 0, sizeof(inmst));
    memset(sel, 0, sizeof(sel));
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> monke[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            a[i][j] = a[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        }
    }
    /**********************************************************
    Let's not forget that a[i][j] is the SQUARE of the distance
    ***********************************************************/
    inmst[1] = 1;
    int cnt = 1; // number of nodes in the mst; used to check if loop is done
    int _min;
    int min_i, min_j;
    while (cnt < n) {
        _min = 0x7fffffff;
        for (int i = 1; i <= n; i++) {
            if (inmst[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!inmst[j]) {
                        if (_min > a[i][j]) {
                            _min = a[i][j];
                            min_i = i, min_j = j;
                        }
                    }
                }
            }
        }
        sel[min_i][min_j] = sel[min_j][min_i] = 1;
        inmst[min_j] = 1;
        cnt++;
    }
    int _max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (sel[i][j]) {
                _max = max(a[i][j], _max);
                // cout << i << ' ' << j << ' ' << sqrt(a[i][j]) << endl;
            }
        }
    }
    cnt = 0; // reusing cnt for counting monkeys for final answer
    for (int i = 1; i <= m; i++) {
        if (monke[i] * monke[i] >= _max) {
            cnt++;
        }
    }
    cout << cnt << endl;
}