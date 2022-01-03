#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[1001][1001];
int main() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    int x, y;
    int confcnt = 0;
    vector<int> out;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        if (x > 1) {
            if (cnt[x - 1][y] == 2) confcnt++;
            cnt[x - 1][y]++;
        }
        if (x < n) {
            if (cnt[x + 1][y] == 2) confcnt++;
            cnt[x + 1][y]++;
        }
        if (y > 1) {
            if (cnt[x][y - 1] == 2) confcnt++;
            cnt[x][y - 1]++;
        }
        if (y < n) {
            if (cnt[x][y + 1] == 2) confcnt++;
            cnt[x][y + 1]++;
        }
        if (x > 1) {
            if (cnt[x - 1][y] == 3) confcnt--;
            cnt[x - 1][y]++;
        }
        if (x < n) {
            if (cnt[x + 1][y] == 3) confcnt--;
            cnt[x + 1][y]++;
        }
        if (y > 1) {
            if (cnt[x][y - 1] == 3) confcnt--;
            cnt[x][y - 1]++;
        }
        if (y < n) {
            if (cnt[x][y + 1] == 3) confcnt--;
            cnt[x][y + 1]++;
        }
        out.push_back(confcnt);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << j <<
    }
    for (auto i : out) {
        cout << i << endl;
    }
}