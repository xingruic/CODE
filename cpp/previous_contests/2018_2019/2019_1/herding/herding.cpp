#include<bits/stdc++.h>
using namespace std;
int cow[3];
int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> cow[0] >> cow[1] >> cow[2];
    if (cow[1] == cow[0] + 1 && cow[2] == cow[1] + 1) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }
    bool t = 1;
    for (int j, i = 0; i < 2; i++) {
        j = i + 1;
        if (abs(cow[j] - cow[i]) == 2) {
            cout << 1 << endl;
            t = 0;
            break;
        }
    }
    if (t) cout << 2 << endl;
    int x, y, m = 0, j;
    for (int i = 0; i < 2; i++) {
        j = i + 1;
        if (abs(cow[j] - cow[i]) > m) {
            m = abs(cow[j] - cow[i]);
            x = i, y = j;
        }
    }
    cout << m - 1 << endl;
    cerr << cow[x] << ' ' << cow[y] << endl;
}