#include<bits/stdc++.h>
using namespace std;
int n;
bool a[1001]; // true if odd, false if even
int odd = 0, even = 0;
int main() {
    {
        cin >> n;
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            a[i] = (x % 2);
            if (a[i]) odd++;
            else even++;
        }
    }
    while (odd > even) {
        odd -= 2;
        even++;
    }
    if (even > odd + 1) even = odd + 1;
    cout << even + odd << endl;
}