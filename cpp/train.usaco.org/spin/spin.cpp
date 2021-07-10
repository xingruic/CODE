#include<bits/stdc++.h>
#define DEBUG
using namespace std;
struct wheel {
    vector<pair<int, int> > wedges;
    int speed;
    int rot = 0;
}wheels[5];
bool thru[360];
bool check() {
    for (int i = 0; i < 360; i++) {
        for (int j = 0; j < 5; j++) {
            for (auto k : wheels[j].wedges) {
                if (k.first > thru[i] && k.second < thru[i]) {
                    thru[i] = 0;
                    break;
                }
            }
            if (thru[i] == 0) break;
        }
    }
    if (find(thru, thru + 360, 1) != thru + 360) return 1;
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
void spin() {
    for (int i = 0; i < 5; i++) {
        wheels[i].rot += wheels[i].speed;
        wheels[i].rot %= 360;
#ifdef DEBUG
        for (auto j : wheels[i].wedges) {
            cerr << (j.first + wheels[i].rot) % 360 << ',' << (j.second + wheels[i].rot) % 360 << '\t';
        }cerr << endl;
#endif
    }
#ifdef DEBUG
    cerr << endl;
#endif
    int h = _hash();
    if (find(hashes.begin(), hashes.end(), h) != hashes.end()) {
        cout << "none" << endl;
        exit(0);
    }
    hashes.push_back(h);
}
int main() {
    memset(thru, 0, sizeof(thru));
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
    int i;
    for (i = 0;!check();i++) {
        spin();
    }
    cout << i << endl;
    return 0;
}