#include<bits/stdc++.h>
using namespace std;
int n, m;
bool stall[201];
bool used[201];
int ans = 0;
void stalls(int i = 1) { // stalls(cow #)
    if (i == n) {
        ans++;
        return;
    }
    bool f=0;
    for (int j = 1; j <= m; j++) {
        if (!used[i] && stall[i]) {
            f=1;
            used[i] = 1;
            stalls(i + 1);
            used[i] = 0;
        }
    }
}
int main() {
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    memset(stall, 0, sizeof(stall));
    memset(used, 0, sizeof(used));
    cin >> n >> m;
    char t;
    for (int i = 1; i <= n; i++) {
        while ((t = getchar()) != '\n') {
            stall[t - '0'] = 1;
        }
    }
    stalls();
    cout << ans << endl;
}