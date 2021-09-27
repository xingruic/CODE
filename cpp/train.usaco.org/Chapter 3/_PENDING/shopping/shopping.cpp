#include<bits/stdc++.h>
using namespace std;
int s; // number of special offers
struct offer {
    int n; // number of products included
    int p; // price of this offer
    struct Prod {
        int id; // id of this included item
        int items; // number of items of this product included
    }prod[6];
}offers[100]; // special offers
int b; // number of products to buy
int code[1000]; // each product id that is useful is assigned a smaller number
int items[6]; // how many items of this product to buy
int price[6]; // price of this item
int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    memset(code, 0, sizeof(code));
    memset(items, 0, sizeof(items));
    memset(price, 0, sizeof(price));
    memset(offers, 0, sizeof(offers));
    {
        cin >> s;
        for (int i = 1; i <= s; i++) {
            cin >> offers[i].n;
            for (int j = 1; j <= s; j++) {
                cin >> offers[i].prod[j].id >> offers[i].prod[j].items;
            }
            cin >> offers[i].p;
        }
        cin >> b;
        int c;
        for (int i = 1; i <= b; i++) {
            cin >> c >> items[i] >> price[i];
            code[c] = i;
        }
    }
    for (int i = 1; i <= s; i++)
        cout << offers[i].prod[1].id << ' ' << offers[i].p << endl;
    cout << endl;
    int dp[6][6][6][6][6]; // least price to get from dp[0][0][0][0][0] to dp[a][b][c][d][e];
    memset(dp, 0x3d, sizeof(dp));
    for (int i = 0; i <= items[1]; i++) {
        for (int j = 0; j <= items[2]; j++) {
            for (int k = 0; k <= items[3]; k++) {
                for (int l = 0; l <= items[4]; l++) {
                    for (int m = 0; m <= items[5]; m++) {
                        if (i == 0 && j == 0 && k == 0 && l == 0 && m == 0) continue;
                        dp[i][j][k][l][m] = (
                            i * price[i] +
                            j * price[j] +
                            k * price[k] +
                            l * price[l] +
                            m * price[m]
                            );
                        cout << dp[i][j][k][l][m] << ' ';
                        for (int n = 1; n <= s; n++) {
                            int _m[6]; // m for minus
                            memset(_m, 0, sizeof(_m));
                            for (int o = 1; o <= offers[n].n; o++) {
                                _m[code[offers[n].prod[o].id]] = offers[n].prod[o].items;
                                if (_m[1] > i || _m[2] > j || _m[3] > k || _m[4] > l || _m[5] > m) continue;
                                dp[i][j][k][l][m] = min(dp[i][j][k][l][m], dp[i - _m[1]][j - _m[2]][k - _m[3]][l - _m[4]][m - _m[5]] + offers[n].p);
                            }
                        }
                        cout << dp[i][j][k][l][m] << endl;
                    }
                }
            }
        }
    }
    cout << dp[items[1]][items[2]][items[3]][items[4]][items[5]] << endl;
}