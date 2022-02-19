#include<bits/stdc++.h>
using namespace std;
int n;
int a[11];
int main() {
    cin >> n;
    bool one = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) one = 1;
    }
    if (one) {
        cout << 0 << endl;
        exit(0);
    }

}