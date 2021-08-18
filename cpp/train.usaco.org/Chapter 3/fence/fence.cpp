/*
ID:xingrui1
LANG:C++14
TASK:fence
*/
#include<bits/stdc++.h>
using namespace std;
int a[501][501];
int cnt[501] = { 0 }, n, m;
vector<int> circuit;
void find_circuit(int i) {
    for (int j = 1; j <= m; j++) {
        if (j == i) continue;
        if (!a[i][j]) continue;
        a[i][j] = a[j][i] = a[j][i] - 1;
        find_circuit(j);
    }
    circuit.push_back(i);
}
int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    // freopen("fence.err", "w", stderr);
    memset(a, 0, sizeof(a));
    {
        cin >> n;
        int a, b;
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            ::a[a][b] = ::a[b][a] = ::a[b][a] + 1;
            cnt[a]++, cnt[b]++;
            m = max(m, max(a, b));
        }
    }
    bool odd = 0;
    for (int i = 1; i <= m; i++) if (cnt[i] % 2 == 1) {
        find_circuit(i);
        odd = 1;
        break;
    }
    if (!odd) find_circuit(1);
    for (auto i = circuit.end() - 1; i != circuit.begin(); i--) cout << *i << endl;
    cout << *circuit.begin() << endl;
}