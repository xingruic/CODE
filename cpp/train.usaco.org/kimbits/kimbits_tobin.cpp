/*
TASK:kimbits
ID:xingrui1
LANG:C++
*/
#include<iostream>
#include<memory.h>
#include<assert.h>
#include<algorithm>
#include<time.h>
using namespace std;
int N, L, I;
char result[31]; // for tobin function, using char as int
void tobin(int x) { // stores result in global result[N]
    memset(result, 0, sizeof(result));
    for (int i = N - 1; x > 0; i--) {
        if (i < 0) {
            result[0] = -1;
            return;
        }
        result[i] = x % 2;
        x /= 2;
    }
}
int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    clock_t t = clock();
    cin >> N >> L >> I;
    for (int i = 0; i < I; i++) {
        tobin(i);
        assert(result[0] >= 0);
        if (count(result, result + N, 1) > L) {
            I++;
            continue;
        }
    }
    bool print = 0;
    for (int i = 0; i < N; i++) {
        cout << (int)result[i];
    }cout << endl;
    cout << (clock() - t) * 1.0 / CLOCKS_PER_SEC << endl;
}