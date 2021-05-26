#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("out.txt", "w", stdout);
    // input
    int n, p;
    cin >> n >> p;
    int C[n + 1], U[n + 1]; // ³õÊ¼×´Ì¬ ãÐÖµ
    for (int i = 1; i <= n; i++)
    {
        cin >> C[i] >> U[i];
        if (C[i] == 0)
            C[i] = -1 * U[i];
    }
    int W[n + 1][n + 1];
    memset(W, 0x3d, sizeof(W));
    bool print[n + 1]; // Êä³ö
    memset(print, 1, sizeof(print));
    int x, y, w;
    for (int i = 1; i <= p; i++)
    {
        cin >> x >> y >> w;
        W[x][y] = w;
        print[x] = 0;
    }

    // bfs
    queue<int> q;
    for (int j = 1; j <= n; j++)
        if (C[j] > 0)
            q.push(j);
    while (!q.empty())
    {
        int j = q.front();
        q.pop();
        if (C[j] <= 0)
            continue;
        for (int i = 1; i <= n; i++)
        {
            if (W[j][i] < 1027423549)
            {
                C[i] += W[j][i] * C[j]; // sigma = sum it up
                // cout << i << " : " << W[j][i] << " * " << C[j] << " + " << C[i] - W[j][i] * C[j] << " = " << C[i] << endl;
                q.push(i);
                W[j][i] = 1027423549; // avoid double
            }
        }
    }
    bool out = 0;
    for (int i = 1; i <= n; i++)
    {
        if (print[i] && C[i] > 0)
        {
            out = 1;
            cout << i << ' ' << C[i] << endl;
        }
    }
    if (!out)
        cout << "NULL" << endl;
    return 0;
}