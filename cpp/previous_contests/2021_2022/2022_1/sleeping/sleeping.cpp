#include<bits/stdc++.h>
using namespace std;
int t;
int n[11];
vector<int> a[11];
vector<int> v;
void print(vector<int> x) {
    for (auto j : x) cout << j << ' ';
    cout << endl;
}
int main() {
    {
        cin >> t;
        int tmp;
        for (int i = 1; i <= t; i++) {
            cin >> n[i];
            a[i].push_back(-1);
            for (int j = 1; j <= n[i]; j++) {
                cin >> tmp;
                a[i].push_back(tmp);
            }
        }
    }
    for (int i = 1; i <= t; i++) {
        int maxa = 0, sum = 0;
        bool f = 1;
        for (int j = 1; j < n[i]; j++)
            if (a[i][j] != a[i][j + 1]) f = 0;
        if (f) {
            cout << 0 << endl;
            continue;
        }
        for (int j = 1; j <= n[i]; j++) {
            maxa = max(maxa, a[i][j]);
            sum += a[i][j];
        }
        // cout << maxa << ' ' << sum << endl;
        int mincnt = 0x7fffffff;
        for (int k = maxa; k <= sum; k++) {
            v = a[i];
            int cnt = 0;
            for (int j = 1; j < n[i]; j++) {
                if (a[i][j] + a[i][j + 1] <= k) {
                    cnt++;
                    a[i][j + 1] += a[i][j];
                    a[i][j] = -1;
                }
                // print(a[i]);
            }
            sort(a[i].begin(), a[i].end());
            f = 0;
            for (int j = 1; j < n[i]; j++) {
                if (a[i][j] != a[i][j + 1] && a[i][j] != -1 && a[i][j + 1] != -1) {
                    // cout << j << endl;
                    f = 1;
                    break;
                }
            }
            a[i] = v;
            if (f) continue;
            cout << cnt << endl;
            break;
        }
    }
}