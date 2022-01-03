#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt = 0;
void lonely(int x) {
    int t = 0;
    for (int i = x - 1; i >= 0; i--) {
        if (s[i] != s[x]) {
            t++;
        }
        else {
            break;
        }
    }
    int u = 0;
    for (int i = x + 1; i < n; i++) {
        if (s[i] != s[x]) {
            u++;
        }
        else {
            break;
        }
    }
    int tmp = min(u, t) * 2 + 1;
    // if (tmp >= 3) cout << tmp << ' ';
    if (max(u, t) > 1) {
        cnt += abs(t - u);
        if (min(t, u) == 0) cnt--;
        // cout << abs(t - u) << endl;
    }
    for (int i = 3; i <= tmp; i++) {
        cnt += i - 2;
    }
}
int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        lonely(i);
    }
    cout << cnt;
}