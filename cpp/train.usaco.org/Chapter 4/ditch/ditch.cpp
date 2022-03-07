#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[201], e[201], c[201];
int ans = 0;
void find(vector<int> been, int x = 1, int cap = 0x7fffffff) {
    if (x == m) {
        ans += cap;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] = x) {
            bool f = 0;
            for (auto j : been) {
                if (j == e[i]) {
                    f = 1;
                    return;
                }
            }
            been.push_back(x);
            find(been, e[i], min(cap, c[i]));
            been.pop_back();
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> c[i];
    }
    vector<int> been;
    find(been, 1, 0x7fffffff);
    cout << ans << endl;
}