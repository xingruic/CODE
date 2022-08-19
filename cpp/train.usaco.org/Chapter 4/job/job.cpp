/*
ID: xingrui1
LANG: C++17
TASK: job
*/
#include<bits/stdc++.h>
using namespace std;
int n, m1, m2;
// int a[21], b[21]; // stores the number of machines with i processing time
int A[31], B[31];
int main() {
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    // memset(a, 0, sizeof(a));
    // memset(b, 0, sizeof(b));
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        cin >> A[i];
        // a[A[i]]++;
    }
    for (int i = 1; i <= m2; i++) {
        cin >> B[i];
        // b[B[i]]++;
    }
    sort(A, A + m1);
    sort(B, B + m2);

    // minimum time to complete A tasks
    int tasks = n;
    int wta[31];
    memset(wta, 0, sizeof(wta));
    int time = 0;
    bool finished = 0;
    while (true) {
        for (int i = 1; i <= m1; i++) {
            if (tasks == 0) break;
            if (wta[i] == 0) {
                wta[i] = A[i];
                tasks--;
            }
        }
        finished = 1;
        if (tasks > 0) finished = 0;
        for (int i = 1; i <= 30; i++) if (wta[i] > 0) wta[i]--, finished = 0;
        if (finished) break;
        time++;
    }
    cout << time << ' ';

    // minimum time for all tasks
    tasks = n;
    int btasks = 0;
    memset(wta, 0, sizeof(wta));
    int wtb[31];
    memset(wtb, 0, sizeof(wtb));
    time = 0;
    finished = 0;
    while (true) {
        for (int i = 1; i <= m1; i++) {
            if (tasks == 0) break;
            if (wta[i] == 0) tasks--, wta[i] = A[i];
        }
        for (int i = 1; i < m2; i++) {
            if (btasks == 0) break;
            if (wtb[i] == 0) btasks--, wtb[i] = B[i];
        }
        finished = 1;
        if (tasks > 0 || btasks > 0) finished = 0;
        for (int i = 1; i <= 30; i++) {
            if (wta[i] > 0) {
                finished = 0;
                if (wta[i] == 1) btasks++;
                wta[i]--;
            }
            if (wtb[i] > 0) {
                finished = 0;
                wtb[i]--;
            }
        }
        if (finished) break;
        time++;
    }
    cout << time << endl;
}