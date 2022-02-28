#include<bits/stdc++.h>
using namespace std;
int n;
string cubes[5], words[11];
bool yes[11];
int main() {
    memset(yes, 0, sizeof(yes));
    cin >> n;
    for (int i = 1; i <= 4; i++) {
        cin >> cubes[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j == i) continue;
            for (int k = 1; k <= 4; k++) {
                if (k == j || k == i) continue;
                for (int x = 0; x < 6; x++)
                    for (int y = 0; y < 6; y++)
                        for (int z = 0; z < 6; z++) {
                            for (int u = 1; u <= n; u++) {
                                if (words[u].size() == 3) {
                                    if (
                                        words[u][0] == cubes[i][x] &&
                                        words[u][1] == cubes[j][y] &&
                                        words[u][2] == cubes[k][z]
                                        )
                                    {
                                        yes[u] = 1;
                                    }
                                }
                            }
                        }
                for (int l = 1; l <= 4; l++) {
                    if (l == k || l == j || l == i) continue;
                    for (int x = 0; x < 6; x++)
                        for (int y = 0; y < 6; y++)
                            for (int z = 0; z < 6; z++)
                                for (int w = 0; w < 6; w++) {
                                    for (int u = 1;u <= n; u++) {
                                        if (words[u].size() == 4) {
                                            if (
                                                words[u][0] == cubes[i][x] &&
                                                words[u][1] == cubes[j][y] &&
                                                words[u][2] == cubes[k][z] &&
                                                words[u][3] == cubes[l][w]
                                                )
                                            {
                                                yes[u] = 1;
                                            }
                                        }
                                    }
                                }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (yes[i] ? "YES" : "NO") << endl;
    }
}