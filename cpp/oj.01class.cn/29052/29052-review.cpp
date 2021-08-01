// Mon, Jul 19, 2021
#include<bits/stdc++.h>
using namespace std;
int N, K, M, S, T; // No. of countries, no. of cultures, no. of paths between countries, starting country, ending country
int C[101], A[101][101]; // The culture of each country, adjacency matrix for countries (bidirectional, weighted)
bool H[101][101]; // Adjacency matrix for hate (directional, non-weighted)
int main() {
    memset(C, 0, sizeof(C));
    memset(A, 0x3d, sizeof(A));
    memset(H, 0, sizeof(H));
    freopen("29052.in", "r", stdin);
    freopen("29052.out", "w", stdout);
    {
        cin >> N >> K >> M >> S >> T;
        for (int i = 1; i <= N; i++) cin >> C[i];
        for (int i = 1; i <= K; i++)
            for (int j = 1; j <= K; j++)
                cin >> H[i][j];
        int a, b, x;
        for (int i = 1; i <= M; i++) {
            cin >> a >> b >> x;
            A[a][b] = A[b][a] = x;
        }
    }
    // slightly modified dijkstra
    vector<int> c; // cultures he has already learned
    queue<int> q;
    int dist[N + 1];
    memset(dist, 0x3d, sizeof(dist));
    int last[N + 1];
    memset(last, -1, sizeof(last));
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        c.push_back(C[t]);
        for (int i = 1; i <= N; i++) {
            // cout << i << ' ' << t << ' ' << H[i][t] << endl;
            bool h = 0;
            for (auto j : c) {
                if (H[C[i]][j] || C[i] == j) {
                    h = 1;
                    break;
                }
            }
            if (h) continue;
            if (A[t][i] < 0x3c3c3c3c) {
                if (dist[i] > 0x3c3c3c3c || A[t][i] + dist[t] < dist[i]) {
                    dist[i] = A[t][i] + dist[t];
                    last[i] = t;
                    // cout << t << "->" << i << endl;
                    q.push(i);
                }
            }
        }
        // for (int i = 1; i <= N; i++) cout << dist[i] << ' ';
        // cout << endl;
    }
    {
        int i = T;
        while (last[i] != -1) {
            cout << i << ' ';
            i = last[i];
        }cout << endl;
    }
    if (dist[T] > 0x3c3c3c3c) cout << -1 << endl;
    else cout << dist[T] << endl;
}