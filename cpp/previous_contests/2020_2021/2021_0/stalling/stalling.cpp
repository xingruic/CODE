#include<bits/stdc++.h>
using namespace std;
int n;
int a[21], b[21]; // heights of the cows, heights of the stalls
int cnt = 0;
void stall(int x, bool stalls[21]) {
    if (x > 20) {
        cnt++;
        return;
    }
    for (int i = 1; i <= 20; i++)
        if (!stalls[i])
            if (a[x] <= b[i]) {
                // cout << endl;
                stalls[i] = 1;
                stall(x + 1, stalls);
                stalls[i] = 0;
            }
    return;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    bool stalls[21];
    memset(stalls, 0, sizeof(stalls));
    stall(1, stalls);
    cout << cnt << endl;
}