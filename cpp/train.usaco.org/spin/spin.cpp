#include<bits/stdc++.h>
#define DEBUG
using namespace std;
struct wheel {
    vector<pair<int, int>> wedges;
    int speed;
    int rot = 0;
}wheels[5];
bool thru[360];
bool check() {
    memset(thru, 1, sizeof(thru));
    for (int i = 0; i < 360; i++) {
        cerr << '[';
        for (int j = 0; j < 5; j++) {
            for (auto k : wheels[j].wedges) {
#ifdef DEBUG
                cerr << k.first << ',' << k.second << ' ';
#endif
                if ((k.first <= k.second && k.first <= i && k.second >= i) || (k.first > k.second && (k.second >= i || k.first <= i))) {
#ifdef DEBUG
                    cerr << "break";
#endif
                    thru[i] = 0;
                    break;
                }
            }
            if (!thru[i]) break;
        }
        if (thru[i]) return 1;
#ifdef DEBUG
        cerr << ']' << ' ';
#endif
    }
#ifdef DEBUG
    cerr << endl;
#endif
    return 0;
}
vector<int> hashes;
int _hash() {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        res = res * 7 + wheels[i].rot;
        // cerr << res << ' ';
    }
    res %= 164093;
    // cerr << res << endl;
    return res;
}
int cnt;
void spin() {
    for (int i = 0; i < 5; i++) {
        wheels[i].rot += wheels[i].speed;
        wheels[i].rot %= 360;
    }
    int h = _hash();
    if (find(hashes.begin(), hashes.end(), h) != hashes.end()) {
        cout << "none" << endl;
        exit(0);
    }
    hashes.push_back(h);
}
int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    freopen("spin.err", "w", stderr);
    {
        int w, a, b;
        for (int i = 0; i < 5; i++) {
            cin >> wheels[i].speed >> w;
            for (int j = 0; j < w; j++) {
                cin >> a >> b;
                wheels[i].wedges.push_back(make_pair(a, (a + b) % 360));
            }
        }
    }
    for (cnt = 0;!check();cnt++) {
        spin();
    }
    cout << cnt << endl;
    return 0;
}