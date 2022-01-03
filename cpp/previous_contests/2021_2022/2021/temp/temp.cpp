#include<bits/stdc++.h>
using namespace std;
int n;
int p[100001], a[100001];
short adj[100001] = { 0 };
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        adj[i] = p[i] - a[i];
    }
    bool plus = 0;
    int cnt = 0;
    bool done;
    do {
        done = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 1) cnt++;
            if (adj[i] > 0) {
                done = 0;
                if (plus == 1) {
                    plus = 0;
                    cnt++;
                }
                adj[i]--;
            }
            else if (adj[i] < 0) {
                done = 0;
                if (plus == 0) {
                    plus = 1;
                    cnt++;
                }
                adj[i]++;
            }
        }
    } while (!done);
    cout << cnt << endl;
}