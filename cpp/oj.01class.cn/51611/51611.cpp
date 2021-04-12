#include <bits/stdc++.h>
using namespace std;
struct step
{ // contains the x of this step, the y of this step, and the time elapsed before this step
    int x, y, t;
    step(int xx = 0, int yy = 0, int tt = 0)
    {
        x = xx, y = yy, t = tt;
    }
    bool operator==(step other)
    {
        return x == other.x && y == other.y && t == other.t;
    }
};
int m;
int times[301][301];
int ans = 0x7fffffff;
void dfs(step t)
{
    if (t.t >= ans)
        return;
    if (times[t.x][t.y] - t.t <= 0)
        return;
    if (times[t.x][t.y] == -1)
    {
        ans = t.t;
        return;
    }
}
int main()
{
    cin >> m;
    memset(times, -1, sizeof(times));
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        times[x][y] = t;
        times[x + 1][y] = min(times[x + 1][y], t);
        if (x > 0)
            times[x - 1][y] = min(times[x - 1][y], t);
        times[x][y + 1] = min(times[x][y + 1], t);
        if (x > 0)
            times[x][y - 1] = min(times[x][y - 1], t);
    }
    dfs(step(0, 0, 0));
    cout << (ans == 0x7fffffff ? -1 : ans) << endl;
}