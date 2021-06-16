#include<bits/stdc++.h>
using namespace std;
int d[35][35] = { 0 }, ans[35];
int main() {
    int N, L;
    long long I;
    scanf("%d%d%lld", &N, &L, &I);
    for (int i = 0; i <= N; i++)d[i][0] = d[0][i] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (j <= i)
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            else d[i][j] = d[i][i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) cout << d[i][j] << '\t';
        cout << endl;
    }
    for (int i = N; i >= 1; i--) {
        if (I > d[i - 1][L]) {
            cout << '1';
            I -= d[i - 1][L];
            L--;
        } else cout << '0';
    }
    cout << '\n';
    return 0;
}
