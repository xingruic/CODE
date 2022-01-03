#include<bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001];
int d[100001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) d[i] = a[i] - b[i];
    int cnt;
    bool add;
    bool done;
    int start = 1;
    while (start <= n) {
        add = (d[start] < 0);
        done = 1;
        int i;
        bool equal = 0;
        for (i = start; i <= n; i++) {
            if (d[i] == 0) break;
            if (d[i] < 0 && add == 0) break;
            if (d[i] > 0 && add == 1) break;
        }
        start = i;
        while (d[start] == 0) start++;
        int m;
        if (add) {
            m = 0;
            for (int j = 1; j < i; j++) m = max(m, d[j]);
            for (int j = 1; j < i; j++) d[j] += abs(m);
            cnt += m;
        }
        else {
            m = 0x7fffffff;
            for (int j = 1; j < i; j++) m = min(m, d[j]);
            for (int j = 1; j < i; j++) d[j] -= abs(m);
            cnt += m;
        }
    }
    cout << cnt << endl;
}