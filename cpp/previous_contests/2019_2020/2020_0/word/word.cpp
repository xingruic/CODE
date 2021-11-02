#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int cnt = 0;
    string s;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (cnt + s.size() > k) {
            cout << '\n' << s;
            cnt = s.size();
            continue;
        }
        if (cnt > 0) cout << ' ' << s;
        else cout << s;
        cnt += s.size();
    }
}