#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("in.in","r",stdin);
    // freopen("out.out","w",stdout);
    int t, n;
    cin >> t >> n;
    int a[n + 1][n + 1];
    int dist[n + 1];
    memset(a, 0x3c, sizeof(a));
    memset(dist, 0x3c, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i <= n; i++) a[i][i] = 0;
    for (int i = 0; i < t; i++) {
        int q, b, c;
        cin >> q >> b >> c;
        a[q][b] = min(a[q][b], c);
        a[b][q] = min(a[b][q], c);
    }
    bool included[n + 1];
    memset(included, 0, sizeof(included));
    included[1] = 1;
    while (1) {
        bool did_stuff = 0;
        for (int i = 1; i <= n; i++) {
            if (included[i]) {
                for (int j = 1; j <= n; j++) {
                    if (a[i][j] < 0x33333333) {
                        // cout<<a[i][j]<<' '<<i<<' '<<j<<endl;
                        if (!included[j]) did_stuff = 1;
                        included[j] = 1;
                        if (dist[j] > dist[i] + a[i][j]) {
                            dist[j] = dist[i] + a[i][j];
                            did_stuff = 1;
                        }
                    }
                }
            }
        }
        if (did_stuff == 0) break;
    }
    cout << dist[n] << endl;
}