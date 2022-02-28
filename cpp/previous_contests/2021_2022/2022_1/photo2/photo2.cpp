#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001], b[100001];
int aid[100001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        aid[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] != a[i]) cnt++;
        for (int k = aid[b[i]]; k > i; k--) {
            swap(a[k], a[k - 1]);
            swap(aid[a[k]], aid[a[k - 1]]);
        }
        // for (int j = 1; j <= n; j++) {
        //     cout << a[j] << ' ';
        // }cout << endl;
    }
    cout << cnt << endl;
}