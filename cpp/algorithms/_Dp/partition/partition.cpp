#include<bits/stdc++.h>
using namespace std;
int k, n; // number, no. of parts
int p[0x7fff][0x7fff];
int partition(int a, int b) { // reflects k and n, respectively
    if (p[a][b] != 0) return p[a][b];
    if (b > a) return p[a][b] = partition(a, a);
    if (b == 1) return p[a][b] = 1;
    int sum = 1;
    for (int i = 2; i <= b; i++) {
        int t = a - i;
        // int ts = sum;
        sum += partition(t, i);
        // cout << t << ' ' << i << ' ' << sum - ts << endl;
    }
    return p[a][b] = sum;
}
int main() {
    cin >> k >> n;
    int t = clock();
    memset(p, 0, sizeof(p));
    cout << partition(k, n) << endl;
    cout << "Done in " << (clock() - t) * 1.0 / CLOCKS_PER_SEC << 's' << endl;
}