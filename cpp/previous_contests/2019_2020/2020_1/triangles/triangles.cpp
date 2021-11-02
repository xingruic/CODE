#include<bits/stdc++.h>
using namespace std;
int n;
int x[101], y[101];
int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    int area = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                // https://sciencing.com/area-triangle-its-vertices-8489292.html
                // area = the absolute value of Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By) divided by 2
                int t = abs(x[i] * (y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j])); // divided by 2 then multiplied by 2
                area = max(area, t);
            }
        }
    }
    cout << area << endl;
}