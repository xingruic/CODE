#include<bits/stdc++.h>
using namespace std;
int n;
struct animal {
    int k;
    string attr[101];
}anim[101];
int maxcnt = 0;
int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> anim[i].k;
        for (int j = 1; j <= anim[i].k; j++) {
            cin >> anim[i].attr[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cnt = 0;
            for (int k = 1; k <= anim[i].k; k++) {
                for (int l = 1; l <= anim[j].k; l++) {
                    if (anim[i].attr[k] == anim[j].attr[l]) {
                        cnt++;
                        cout << "E" << endl;
                    }
                }
            }
            if (cnt > maxcnt) maxcnt = cnt;
        }
    }
    cout << maxcnt + 1 << endl;
}