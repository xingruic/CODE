#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[201], e[201], c[201];
struct Edge {
    int a, b, x;
    Edge(int s, int e, int c) :a(s), b(e), x(c) {}
};
vector<Edge> edges;
int ans = 0;
void find(vector<int> been, int x = 1, int cap = 0x7fffffff) {
    if (x == m) {
        for (int i = 1; i < been.size(); i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (edges[j].a == been[i - 1] && edges[j].b == been[i]) {
                    edges[j].x -= cap;
                    if (edges[j].x == 0) {
                        swap(edges[j].a, edges[j].b);
                    }
                }
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] = x) {
            bool f = 0;
            for (auto j : been) {
                if (j == e[i]) {
                    f = 1;
                    break;
                }
            }
            if (f) continue;
            been.push_back(x);
            find(been, e[i], min(cap, c[i]));
            been.pop_back();
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> e[i] >> c[i];
        edges.push_back(Edge(s[i], e[i], c[i]));
    }
    vector<int> been;
    find(been, 1, 0x7fffffff);
    cout << ans << endl;
}