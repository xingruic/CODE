/*
TASK:game1
ID:xingrui1
LANG:C++
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int board[150]; // the game board
int best[150][150]; // the best points if you're going first with the board from i to j
int total[150][150];
int main() {
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);
    memset(best, 0, sizeof(best));
    memset(total, 0, sizeof(total));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
        best[i][i] = board[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            total[i][j] = board[j] + total[i][j - 1];
            // cout << i << ' ' << j << ' ' << total[i][j] << endl;
        }
    }
    // this for loop is done this way because it makes the correct order. more explanation in the explanation file.
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            best[i][j] = max(board[i] + (total[i + 1][j] - best[i + 1][j]), board[j] + (total[i][j - 1] - best[i][j - 1]));
        }
    cout << best[1][n] << ' ' << total[1][n] - best[1][n] << endl;
}