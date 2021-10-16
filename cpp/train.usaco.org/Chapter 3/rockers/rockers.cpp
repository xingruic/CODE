/*
ID:xingrui1
LANG:C++
TASK:rockers
*/
#include<bits/stdc++.h>
using namespace std;
int n, t, m;
int song[21]; // stores the length of the song
int ans = 0;
void solve(int x = 0, int y = 0, int z = 0, int mcnt = 0) { // x=song,y=disk,z=cnt,mcnt=(minute we're on in this disk)
    // cout << x << ' ' << y << ' ' << z << ' ' << mcnt << '\n';
    if (x > n || y >= m && mcnt == t) {
        ans = max(ans, z);
        return;
    }
    if (mcnt + song[x] <= t) {
        if (mcnt + song[x] < t)
            solve(x + 1, y, z + 1, mcnt + song[x]);
        solve(x + 1, y + 1, z + 1, 0);
    }
    solve(x + 1, y, z, mcnt);
}
int main() {
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    cin >> n >> t >> m;
    for (int i = 1; i <= n; i++) cin >> song[i];
    solve();
    cout << ans << endl;
}