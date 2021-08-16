/*
ID:xingrui1
LANG:C++
TASK:spin
*/
#include<bits/stdc++.h>
using namespace std;
int rot[6] = { 0 }, speed[6], cnt = 0;
vector<pair<int, int>> wedges[6];
void spin() {
    cnt++;
    for (int i = 1; i <= 5; i++) {
        rot[i] += speed[i];
        rot[i] %= 360;
    }
}
bool check() {
    bool thru[361];
    memset(thru, 1, sizeof(thru));
    thru[0] = 0;
    for (int i = 1; i <= 360; i++) {
        for (int j = 1; j <= 5; j++) {
            bool f = 0;
            for (auto k : wedges[j]) {
                int t1 = k.first, t2 = k.second;
                k.first += rot[j];
                k.second += rot[j];
                k.first %= 360;
                k.second %= 360;
                if (k.first < k.second && k.first <= i && k.second >= i) {
                    f = 1;
                    // cerr << 1 << endl;
                }
                if (k.first >= k.second && (k.first <= i || k.second >= i)) {
                    f = 1;
                    // cerr << 1 << endl;
                }
                k.first = t1, k.second = t2;
                if (f) break;
            }
            if (!f) {
                thru[i] = 0;
                break;
            }
        }
    }
    auto f = find(thru, thru + 361, 1);
    if (f != thru + 361) {
        // cerr << distance(thru, f) << endl;
        return 1;
    }
    return 0;
}
int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    // freopen("spin.err", "w", stderr);
    {
        int n, a, b;
        for (int i = 1; i <= 5; i++) {
            cin >> speed[i];
            cin >> n;
            for (int j = 1; j <= n; j++) {
                cin >> a >> b;
                wedges[i].push_back(make_pair(a, (a + b) % 360));
            }
        }
    }
    for (int i = 0; i < 360; i++) {
        if (check()) {
            cout << cnt << endl;
            exit(0);
        }
        spin();
        // if (i == 1) {
        //     for (int i = 1; i <= 5; i++) {
        //         for (auto j : wedges[i]) cerr << (j.first + rot[i]) % 360 << '-' << (j.second + rot[i]) % 360 << ',';
        //         cerr << endl;
        //     }
        // }
    }
    cout << "none" << endl;
}