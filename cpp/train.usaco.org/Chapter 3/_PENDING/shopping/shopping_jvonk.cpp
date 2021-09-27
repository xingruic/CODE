#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("shopping.in");
ofstream fout("shopping.out");

struct special_offer {
    int n;
    int price;              // the price of that special offer
    struct product {        // for each product we have to keep :
        int id;             // the id of the product
        int items;          // how many items it includes
    } prod[6];
} so[100];                  // here the special offers are kept

int code[1000],             /* Each code is 'hashed' from its real value
                               to a smaller index.  Example :
                   If in the input we have code 111, 934, 55,
                   1, 66 we code them as 1,2,3,4,5. That is
                   kept in code[1000];
                             */

    price[6],                   // the price of each product
    many[6];                    // how many of each product are to be bought

int s,                      // the number of special offers
b;                      // the number of different kinds of products to be bought

int sol[6][6][6][6][6];     // here we keep the price of each configuration

void init() {               // reads the input
    fin >> s;
    for (int i = 1;i <= s;i++) {
        fin >> so[i].n;
        for (int j = 1;j <= so[i].n;j++)
            fin >> so[i].prod[j].id >> so[i].prod[j].items;
        fin >> so[i].price;
    }
    fin >> b;
    for (int i = 1;i <= b;i++) {
        int tmp;
        fin >> tmp;
        code[tmp] = i; // here we convert the code to an id from 1..5
        fin >> many[i];
        fin >> price[i];
    }
}

void solve() { // the procedure that solves the problem
    for (int a = 0;a <= many[1];a++)
        for (int b = 0;b <= many[2];b++)
            for (int c = 0;c <= many[3];c++)
                for (int d = 0;d <= many[4];d++)
                    for (int e = 0;e <= many[5];e++)
                        if ((a != 0) || (b != 0) || (c != 0) || (d != 0) || (e != 0)) {

                            int min = a * price[1] + b * price[2] + c * price[3] + d * price[4] + e * price[5];
                            /* in min we keep the lowest price at which we can buy a items
                               from the 1st type, +b from the 2nd+c of the 3rd... e from the
                                5th */

                            for (int k = 1;k <= s;k++) { // for each special offer
                                int can = 1, hm[6];
                                memset(&hm, 0, sizeof(hm));
                                for (int l = 1;l <= so[k].n;l++)
                                    hm[code[so[k].prod[l].id]] = so[k].prod[l].items;
                                if ((hm[1] > a) || (hm[2] > b) || (hm[3] > c) || (hm[4] > d) || (hm[5] > e))
                                    can = 0;// we check if it is possible to use that offer

                                if (can) {        // if possible-> check if it is better
                                                  // than the current min
                                    int pr = so[k].price + sol[a - hm[1]][b - hm[2]][c - hm[3]]
                                        [d - hm[4]][e - hm[5]];
                                    /* Those which are not included in the special offer */
                                    if (pr < min) min = pr;
                                }
                            }
                            sol[a][b][c][d][e] = min;

                        }
}

int main() {
    memset(&so, 0, sizeof(so));
    init();
    solve();
    fout << sol[many[1]][many[2]][many[3]][many[4]][many[5]] << endl;
    return 0;
}