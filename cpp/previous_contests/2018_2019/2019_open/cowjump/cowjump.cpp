#include<bits/stdc++.h>
using namespace std;
int n;
int X1[100001], Y1[100001], X2[100001], Y2[100001];
enum orient { ccw, cw, collin };
orient orientation(int X1, int Y1, int X2, int Y2, int x3, int y3) {
    int v1 = (Y2 - Y1) * (x3 - X2) - (y3 - Y2) * (X2 - X1);
    if (!v1) return collin;
    if (v1 > 0) return cw;
    return ccw;
}
bool inter(int i, int j) { // checks for intersection
    orient o1 = orientation(X1[i], Y1[i], X2[i], Y2[i], X1[j], Y1[j]), o2 = orientation(X1[i], Y1[i], X2[i], Y2[i], X2[j], Y2[j]), o3 = orientation(X1[j], Y1[j], X2[j], Y2[j], X1[i], Y1[i]), o4 = orientation(X1[j], Y1[j], X2[j], Y2[j], X2[i], Y2[i]);
    if ((o1 != o2 && o3 != o4) || (o1 == o2 && o2 == o3 && o3 == o4)) return 1;
    return 0;
}
bool intersect[100001][100001];
int numinter[100001];
int main() {
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    memset(intersect, 0, sizeof(intersect));
    memset(X1, 0, sizeof(X1));
    memset(X2, 0, sizeof(X2));
    memset(Y1, 0, sizeof(Y1));
    memset(Y2, 0, sizeof(Y2));
    memset(numinter, 0, sizeof(numinter));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }
    // check for intersections
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cnt += (intersect[i][j] = inter(i, j));
            numinter[i] += intersect[i][j];
            numinter[j] += intersect[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (numinter[i] == cnt) {
            cout << i << endl;
            return 0;
        }
    }
}