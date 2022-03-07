/*
 ID: xingrui1
 PROG: fence6
 LANG: C++11
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 210;
int n, p[maxn], l[maxn];
int len[maxn][maxn], d[maxn][maxn];
struct node {
    int p[9];
    void read(int k, int n) {
        p[0] = k;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i]);
        }
        sort(p, p + n + 1);
    }
    bool check(const node& x) const {
        for (int i = 0; i < 9; ++i) {
            if (p[i] != x.p[i]) {
                return false;
            }
        }
        return true;
    }
} a[maxn];

int Floyd() {
    int res = inf;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i <= k; ++i) {
            if (len[k][i] == inf) {
                continue;
            }
            for (int j = i + 1; j <= k; ++j) {
                res = min(res, d[i][j] + len[j][k] + len[k][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return res;
}


int main() {
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, num1, num2;
        scanf("%d%d%d%d", &x, &l[i], &num1, &num2);
        a[i << 1].read(x, num1), a[(i << 1) + 1].read(x, num2);
    }
    n = m << 1;
    memset(p, -1, sizeof p);
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            p[i] = i;
            for (int j = i + 1; j < n; ++j) {
                if (p[j] == -1 && a[i].check(a[j])) {
                    p[j] = p[i];
                }
            }
        }
    }
    memset(d, 0x3f, sizeof d);
    memset(len, 0x3f, sizeof len);
    for (int i = 0; i < m; ++i) {
        int u = p[i << 1], v = p[(i << 1) + 1];
        d[u][v] = d[v][u] = len[u][v] = len[v][u] = l[i];
    }
    printf("%d\n", Floyd());
    return 0;
}