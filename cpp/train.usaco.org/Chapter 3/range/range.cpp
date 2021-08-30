/*
ID:xingrui
LANG:C++
TASK:range
*/
#include<bits/stdc++.h>
using namespace std;
bool a[251][251];
bool sq[251][251]; // sq[i][j][k] = is there a square of size k with top left corner at i,j ?
int main() {
    cerr << 0 << endl;
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    int n;
    cin >> n;
    memset(sq, 0, sizeof(sq));
    memset(a, 0, sizeof(a));
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j - 1] == '1';
            sq[i][j] = a[i][j]; // squares of size 1
        }
    }
    // cerr << 1 << endl;
    // dp
    for (int l = 2; l <= n; l++) {
        int cnt = 0;
        for (int i = 1; i + l - 1 <= n; i++)
            for (int j = 1; j + l - 1 <= n; j++) {
                sq[i][j] = a[i][j] && sq[i + 1][j] && sq[i][j + 1] && sq[i + 1][j + 1];
                if (sq[i][j]) cnt++;
            }
        if (cnt > 0)cout << l << ' ' << cnt << endl;
    }
    // cerr << 2 << endl;
}