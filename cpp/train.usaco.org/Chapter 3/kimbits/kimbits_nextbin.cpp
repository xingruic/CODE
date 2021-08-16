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
long long N;
int L, I;
char result[31];
void nextbin() {
    for (int i = N - 1; i >= 0; i--) {
        if (result[i] == 0) {
            result[i] = 1;
            for (int j = i + 1; j < N; j++) result[j] = 0;
            return;
        }
    }
    result[0] = -1;
}
int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    clock_t t = clock();
    cin >> N >> L >> I;
    memset(result, 0, sizeof(result));
    for (int i = 0; i < I - 1; i++) {
        nextbin();
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