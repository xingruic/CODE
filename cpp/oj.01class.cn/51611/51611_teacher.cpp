#include <bits/stdc++.h>
using namespace std;
int m, Map[350][350], f[350][350], ans = 2147483647;
void dfs(int x, int y, int t)
{
    if (Map[x][y] <= t || t >= ans || t >= f[x][y]) //优化
        return;
    f[x][y] = t;
    if (Map[x][y] > 2100000000)
    {
        ans = min(t, ans);
        return;
    }
    dfs(x + 1, y, t + 1);
    if (x - 1 >= 0)
        dfs(x - 1, y, t + 1); //判断边界
    dfs(x, y + 1, t + 1);
    if (y - 1 >= 0)
        dfs(x, y - 1, t + 1);
}
int main()
{
    memset(Map, 0x7f, sizeof(Map));
    memset(f, 0xa7f, sizeof(f));
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        Map[x][y] = min(Map[x][y], t);
        Map[x + 1][y] = min(Map[x + 1][y], t); //取最小的time
        if (x - 1 >= 0)                        //判断边界
            Map[x - 1][y] = min(Map[x - 1][y], t);
        Map[x][y + 1] = min(Map[x][y + 1], t);
        if (y - 1 >= 0)
            Map[x][y - 1] = min(Map[x][y - 1], t);
    }
    dfs(0, 0, 0);
    if (ans == 2147483647) //如果没有逃脱
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}