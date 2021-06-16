/*
TASK:kimbits
ID:xingrui1
LANG:C++11
*/
#include<bits/stdc++.h>
using namespace std;
unsigned N, L, I;
int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    cin >> N >> L >> I;
    unsigned dp[N + 1][N + 1]; // size of each one
    memset(dp, 0, sizeof(dp));

    // first get the size of the lists (helps us)
    for (unsigned i = 0; i <= N; i++) dp[i][0] = dp[0][i] = 1;
    for (unsigned i = 1; i <= N; i++) { // i is total number of digits
        for (unsigned j = 1; j <= N; j++) { // j is the number of digits that are '1'
            if (j <= i) { // check if j is within i
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // number of ones that we could add a '1' to and number of ones that we could add a '0' to
            } else { // else fill the side with the last valid scenario
                dp[i][j] = dp[i][i]; // dp[i][i] will be filled because i<=i
            }
        }
    }

    // figure out what to print (weird binary conversion)
    for (unsigned i = N; i >= 1; i--) {
        if (I > dp[i - 1][L]) { // take as much as you can, if you can then print 1, but if you can't then print 0.
            I -= dp[i - 1][L]; // "taking"
            cout << 1;
            L--; // because we used up a 1
        } else {
            cout << 0;
        }
    }
    cout << endl; // formatting issues with usaco
}