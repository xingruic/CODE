#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int b[n];
    for (int i = 1; i < n; i++) cin >> b[i];
    int a[n + 1];
    for (int i = 1; i <= n; i++) a[i] = i;
    cout << a[1] << a[2] << endl;
}