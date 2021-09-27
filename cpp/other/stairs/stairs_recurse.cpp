#include<bits/stdc++.h>
#define INPUT
using namespace std;
int steps;
int mins, maxs;
int cnt;
void minsteps(int step = 0) {
    if (step > steps) return;
    if (step == steps) {
        cnt++;
    }
    for (int i = mins; i <= maxs; i++) {
        minsteps(step + i);
    }
    return;
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