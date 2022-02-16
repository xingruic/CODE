#include <bits/stdc++.h>
using namespace std;
int t;
int a[100001];
int b[100001];
int ans[101];
int main() {
    memset(ans, -1, sizeof(ans));
    cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }
        if (n > 1 && (a[1] > a[2] || a[n] > a[n - 1])) {
            continue;
        }
        int diff = 0; // difference between odd and even digits
        int _min = 0x7fffffff;
        bool f = 1;
        for (int j = 1; j <= n; j++) {
            _min = min(_min, a[j]);
            // if (f)
            //     diff += a[j];
            // else
            //     diff -= a[j];
            b[j] = a[j];
        }
        for (int k = _min; k >= 0; k--) {
            for (int j = 1; j < n; j++) {
                while (b[j] > k && b[j + 1] > k)
                    b[j]--, b[j + 1]--;
            }
            f = 0;
            for (int j = 1; j <= n; j++) {
                if (b[j] != k) {
                    f = 1;
                    break;
                }
            }
            if (f)
                continue;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                cnt += a[j] - k;
            }
            ans[i] = cnt;
            break;
        }
        // ans[i] is defaulted to -1, so no need to set it here
    }
    for (int i = 1; i <= t; i++) {
        cout << ans[i] << endl;
    }
}