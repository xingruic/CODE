#include<bits/stdc++.h>
using namespace std;
long long output() {
    int n;
    long long a[100001];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    if (n == 1) return 0;
    if (a[n] > a[n - 1] || a[1] > a[2]) return -1;
    for (int i = 2; i < n; i++) {
        if (a[i] > a[i - 1]) {
            long long tmp = a[i] - a[i - 1];
            a[i] -= tmp; // feed a[i] and a[i+1] until a[i]=a[i-1]
            a[i + 1] -= tmp;
            ans += tmp * 2;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }cout << endl;
    // same thing backwards to make sure we get everything
    for (int i = n - 1; i > 1; i--) {
        if (a[i] > a[i + 1]) {
            long long tmp = a[i] - a[i + 1];
            a[i] -= tmp;
            a[i - 1] -= tmp;
            ans += tmp * 2;
        }
    }
    if (a[1] < 0 || a[n] < 0) return -1;
    return ans;
}
int main() {
    // freopen("drought.out", "w", stdout);
    // freopen("prob3_bronze_jan22/9.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << output() << endl;
    }
}