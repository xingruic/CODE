#include<bits/stdc++.h>
using namespace std;
int n;
int a[101];
int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxb = 0, minb = 0;
    int t;
    for (int i = n; i >= 1; i--) {
        if (a[i] > -1) {
            if (t < 0)
                t = a[i];
        }
        else if (t > 0) {
            a[i] = t - 1;
            t = a[i];
        }
        else if (t == 0) {
            maxb++, minb++;
            t = -1;
        }
        else {
            maxb++;
        }
    }
    cout << minb << ' ' << maxb << endl;
}