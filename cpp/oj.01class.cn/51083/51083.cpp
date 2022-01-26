#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[301][301];
bool included[301]; // whether the intersection is included in the mst
int main() {
    memset(included, 0, sizeof(included));
    memset(a, -1, sizeof(a));
    cin >> n >> m;
    {
        int x, y, v;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y >> v;
            a[x][y] = a[y][x] = v;
        }
    }
    included[1] = 1;
    int cnt = 1; // how many intersections are included
    int max_min_val = 0; // maximum min_val
    while (cnt < n) {
        int min_val = 0x7fffffff, min_j;
        for (int i = 1; i <= m; i++) {
            if (included[i]) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] >= 0 && !included[j]) {
                        if (a[i][j] < min_val) {
                            min_val = a[i][j];
                            min_j = j;
                        }
                    }
                }
            }
        }
        max_min_val = max(max_min_val, min_val);
        included[min_j] = 1;
        cnt++;
    }
    cout << n - 1 << ' ' << max_min_val << endl;
}