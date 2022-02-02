#include<bits/stdc++.h>
using namespace std;
char ans[4][4], guess[4][4];
int anscnt[26], guesscnt[26];
int greencnt = 0, yellowcnt = 0;
int main() {
    memset(anscnt, 0, sizeof(anscnt));
    memset(guesscnt, 0, sizeof(guesscnt));
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> ans[i][j];
            anscnt[ans[i][j] - 'A']++;
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> guess[i][j];
            guesscnt[guess[i][j] - 'A']++;
            if (guess[i][j] == ans[i][j]) {
                anscnt[ans[i][j] - 'A']--;
                guesscnt[ans[i][j] - 'A']--;
                greencnt++;
            }
        }
    }
    // for (int i = 0; i < 26; i++) {
    //     cout << guesscnt[i] << ' ' << (char)(i + 'A') << endl;
    // }
    for (int i = 0; i < 26; i++) {
        yellowcnt += min(anscnt[i], guesscnt[i]);
        // if (min(anscnt[i], guesscnt[i]) > 0)cout << (char)(i + 'A') << ' ' << anscnt[i] << ' ' << guesscnt[i] << endl;
    }
    cout << greencnt << endl << yellowcnt << endl;
}