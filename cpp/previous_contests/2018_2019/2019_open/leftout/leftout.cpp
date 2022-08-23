#include<bits/stdc++.h>
using namespace std;
int n;
bool facing[1001][1001]; // true = facing to the right
void flipr(int i) {
    for (int j = 1; j <= n; j++) facing[i][j] = !facing[i][j];
}
void flipc(int j) {
    for (int i = 1; i <= n; i++) facing[i][j] = !facing[i][j];
}
void checkL() { // checks for rows/columns filled with L and flips them
    for (int i = 1; i <= n; i++) {
        bool f = 1;
        for (int j = 1; j <= n; j++) {
            if (!facing[i][j]) {
                f = 0;
                break;
            }
        }
        if (f) flipr(i);
    }
    for (int j = 1; j <= n; j++) {
        bool f = 1;
        for (int i = 1; i <= n; i++) {
            if (!facing[i][j]) {
                f = 0;
                break;
            }
        }
        if (f) flipc(j);
    }
}
int main() {
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    memset(facing, 0, sizeof(facing));
    cin >> n;
    char t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            facing[i][j] = (t == 'R');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!facing[i][j]) flipr(i);
        }
    }
    checkL();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (facing[i][j]) {
            cout << i << ' ' << j << endl;
            return 0;
        }
    }
}