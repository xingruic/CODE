#include<bits/stdc++.h>
using namespace std;
int n, m;
int ans = 0;
int mem[31][31];
int passtheball(int x = 1, int cnt = 0) { // y is the number of possible cases starting with the current x and cnt
    if (mem[x][cnt] >= 0) return mem[x][cnt];
    if (cnt == m) {
        if (x == 1) return mem[x][cnt] = 1;
        return mem[x][cnt] = 0;
    }
    return mem[x][cnt] = passtheball(x == n ? 1 : x + 1, cnt + 1) + passtheball(x == 1 ? n : x - 1, cnt + 1);
}
int main() {
    memset(mem, -1, sizeof(mem));
    cin >> n >> m;
    cout << passtheball() << endl;
}