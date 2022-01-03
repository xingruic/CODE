#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int pref[2][500001]; // pref[0=g/1=h][index]
int main() {
    cin >> n;
    cin >> s;
    memset(pref, 0, sizeof(pref));
    pref[0][n] = (s[n - 1] == 'G'), pref[1][n] = !pref[0][n];
    for (int j = n - 1; j >= 1; j--) {
        pref[0][j] = pref[0][j + 1] + (int)(s[j - 1] == 'G');
        pref[1][j] = pref[1][j + 1] + (int)(s[j - 1] == 'H');
    }
    // for (int i = 1; i <= n; i++) cout << pref[0][i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << pref[1][i] << ' ';
    // cout << endl;
    int cnt = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            if ((pref[0][j] - pref[0][j + i]) == 1 || (pref[1][j] - pref[1][j + i]) == 1) cnt++;
        }
    }
    cout << cnt << endl;
}