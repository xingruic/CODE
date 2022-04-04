/*
ID:xingrui1
LANG:C++14
TASK:stall4
*/
#include<bits/stdc++.h>
using namespace std;
int n, m;
bool stall[201][201];
bool used[201];
int use[201];
int ans = 0;
void stalls(int i = 1, int cnt = 0) { // stalls(cow #)
    if (i == n + 2) return;
    ans = max(ans, cnt);
    // cerr << "ans updated" << endl;
    // try to find empty stalls and recurse
    bool f = 0;
    for (int j = 1; j <= m; j++) {
        if (!used[j] && stall[i][j]) { // if we like this spot and it isnt taken
            // cerr << "cow " << i << " takes stall #" << j << endl;
            f = 1; // found an empty spot
            used[j] = 1; // set it as taken
            use[i] = j; // set our spot
            stalls(i + 1, cnt + 1); // recurse
            used[j] = 0; // reset
            use[i] = 0; // reset
        }
    }
    // if theres no empty stalls, ask other cows if they can move to another one that they like
    if (!f) {
        for (int j = 1; j < i; j++) { // find other cow's stall
            if (stall[i][use[j]]) // if we like this stall
                for (int k = 1; k <= m; k++) {
                    if (!used[k] && stall[j][k]) { // if theres another slot that other cow likes
                        // cerr << "cow " << i << " takes stall #" << use[j] << " from cow " << j << ", who moves to stall #" << k << endl;
                        used[k] = 1; // set the new stall as filled
                        use[i] = use[j]; // take the cow's original stall
                        use[j] = k; // move other cow to new stall
                        stalls(i + 1, cnt + 1); // recurse
                        used[k] = 0; // reset
                        use[j] = use[i]; // reset
                        use[i] = 0; // reset
                    }
                }
        }
    }
    stalls(i + 1, cnt);
}
int main() {
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
    memset(stall, 0, sizeof(stall));
    memset(used, 0, sizeof(used));
    memset(use, 0, sizeof(use));
    cin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        int t;
        for (int j = 1; j <= x; j++) {
            cin >> t;
            stall[i][t] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cerr << stall[i][j] << ' ';
        }// cerr << endl;
    }
    stalls();
    cout << ans << endl;
}