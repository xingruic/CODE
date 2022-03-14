/*
ID: xingrui1
TASK: ditch
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[201], e[201], c[201];
struct Edge {
    int x, y, a;
    Edge(int s, int e, int c) :x(s), y(e), a(c) {};
};
vector<Edge> edges;
int ans = 0;
void find(vector<int> been, int x = 1, int cap = 0x7fffffff) {
    if (x == m) {
        for (int i = 1; i < been.size(); i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (edges[j].x == been[i - 1] && edges[j].y == been[i]) {
                    edges[j].a -= cap;
                    if (edges[j].a == 0) {
                        edges[j].a = cap;
                        swap(edges[j].x, edges[j].y);
                    }
                    else {
                        edges.push_back(Edge(edges[j].y, edges[j].x, cap));
                    }
                    ans += cap;
                }
            }
        }
        return;
    }
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].x == x) {
            bool f = 0;
            for (auto j : been) {
                if (j == edges[i].y) {
                    f = 1;
                    break;
                }
            }
            if (f) continue;
            been.push_back(x);
            find(been, edges[i].y, min(cap, edges[i].a));
            been.pop_back();
        }
    }
}
int main() {
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> c[i];
        edges.push_back(Edge(s[i], e[i], c[i]));
    }
    vector<int> been;
    find(been, 1, 0x7fffffff);
    cout << ans << endl;
}