#include<bits/stdc++.h>
using namespace std;
int s; // number of offers
int items[100][6]; // items[offer #][item #]=id of the item included in this offer, 0=nonexistent
int ofrp[100]; // price for this offer, 0=nonexistent
int ofrn[100][6]; // # of this item included in the offer, 0=nonexistent
int b; // number of different items to be purchased
int nmlp[1000]; // this thing's price, 0=nonexistent
int buyn[1000]; // how many to buy, 0=nonexistent
int main() {
    memset(items, 0, sizeof(items));
    memset(ofrp, 0, sizeof(ofrp));
    memset(ofrn, 0, sizeof(ofrn));
    memset(nmlp, 0, sizeof(nmlp));
    memset(buyn, 0, sizeof(buyn));
    {
        cin >> s;
        int x, n, id, p;
        for (int i = 1; i <= s; i++) {
            cin >> x;
            for (int j = 1; j <= x; j++) {
                cin >> n >> id;
                items[i][j] = id;
            }
            cin >> p;
            ofrp[i] = p;
        }
        cin >> b;
        for (int i = 1; i <= b; i++) {
            cin >> id >> n >> p;
            buyn[id] = n;
            nmlp[id] = p;
        }
    }
}