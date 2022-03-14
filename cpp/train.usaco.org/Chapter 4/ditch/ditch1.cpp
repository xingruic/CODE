#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[201], e[201], c[201];
int a[301][301];
bool been[301];
int ans = 0;
void find(int x = 1, int cap = 0x7fffffff) {
    if (x == m) {
        int previ = 1;
        for (int i = 2; i <= m; i++) {
            if (been[i]) {
                a[previ][i] -= cap;
                a[i][previ] += cap;
                previ = i;
            }
        }
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (a[x][i] && !been[i]) {
            been[i] = 1;
            find(i, min(cap, a[x][i]));
            been[i] = 0;
        }
    }
}
int main() {
    memset(a, 0, sizeof(a));
    memset(been, 0, sizeof(been));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> c[i];
        a[s[i]][e[i]] += c[i];
    }
    been[1] = 1;
    find();
    
    cout << ans << endl;
}