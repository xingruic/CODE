#include<bits/stdc++.h>
using namespace std;
int n;
int l[201][201];
int a[101][101];
int num[201][201];
bool segcon[101][101];
int size = 1;
int main() {
    memset(l, 0, sizeof(l));
    memset(num, 0, sizeof(num));
    memset(segcon, 0, sizeof(segcon));
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    {
        cin >> n;
        int s, l, n1, n2, x;
        for (int i = 1; i <= n; i++) {
            cin >> s >> l >> n1 >> n2;
            ::l[size][size + 1] = ::l[size + 1][size] = l;
            for (int j = 1; j <= n1; j++) {
                cin >> x;
                segcon[s][x] = segcon[x][s] = 1;
            }
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            int t = num[i][j];
            for (int k = 1; k <= n; k++) {
                if (segcon[t][k]) {
                    for (int x = 1; x <= n * 2; x++) {
                        for (int y = 1; y <= )
                    }
                }
            }
        }
    }
}