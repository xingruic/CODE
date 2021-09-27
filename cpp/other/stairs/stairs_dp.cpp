#include<bits/stdc++.h>
#define INPUT
using namespace std;
int steps;
int mins, maxs;
int cnt;
void minsteps() {
    int cnt[steps + 1];
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    for (int i = 0; i < steps; i++) {
        for (int j = mins;j <= maxs;j++) {
            if (i + j <= steps) cnt[i + j] += cnt[i];
        }
    }
    ::cnt = cnt[steps];
}
int main() {
#ifdef INPUT
    cin >> steps;
    cin >> mins >> maxs;
#else
    steps = 5, mins = 1, maxs = 2;
#endif
    minsteps();
    cout << cnt << endl;
}