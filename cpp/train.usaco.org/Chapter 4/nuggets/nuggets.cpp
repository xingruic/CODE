/*
ID: xingrui1
TASK: nuggets
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[11];
vector<bool> possible;
bool check(int x) {
    if (x >= a[1]) {
        for (int i = x - a[1]; i <= x; i++) {
            if (possible[i] == 0) return 0;
        }
        return 1;
    }
    return 0;
}
int main() {
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cout << 0 << endl;
            exit(0);
        }
    }
    sort(a + 1, a + n + 1);
    possible.push_back(1);
    int t = a[n] * a[n - 1]; // math formula for the largest number that  numbers cant reperesent
    for (int i = 1;i <= t;i++) {
        possible.push_back(0);
        for (int j = 1; j <= n; j++) {
            if (i >= a[j])
                if (possible[i - a[j]]) {
                    possible[i] = 1;
                    break;
                }
        }
        if (check(i)) {
            cout << i - a[1] - 1 << endl;
            exit(0);
        }
    }
    if (a[1] == 2) cout << 1 << endl;
    else cout << 0 << endl;
    // for (auto j : possible) {
    //     cout << j << ' ';
    // }cout << endl;
}