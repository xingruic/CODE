#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i <= n; i++) cin >> a[i];
    string output = "";
    for (int i = 0; i <= n; i++) {
        if (a[i] == 0) continue;
        if (i == n) {
            if (a[i] > 0) output += '+';
            output += to_string(a[i]);
            continue;
        }
        if (a[i] > 0) {
            if (i > 0) output += '+';
            else {}
        }
        if (a[i] == -1) output += '-';
        else if (abs(a[i]) > 1) output += to_string(a[i]);
        output += (n - i == 1) ? "x" : "x^" + to_string(n - i);
    }
    cout << output << endl;
}