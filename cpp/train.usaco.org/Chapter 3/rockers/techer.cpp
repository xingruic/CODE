# include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, t, m, ans = -999999999, a[N];

void dfs(int i, int now, int s, int sum) {
    if (i > n || s > m) {//歌曲录完或碟片用完时
        ans = max(ans, sum);//更新ans及返回
        return;
    }
    if (t - now >= a[i]) {//如果本张碟片剩余时间足够录下这首歌
        if (t - now > a[i])/*特判仍有间*/
            dfs(i + 1, now + a[i], s, sum + 1);//录入歌曲，不换碟片
        /*正好用完或仍有时间都可换碟片*/
        dfs(i + 1, 0, s + 1, sum + 1); //录入歌曲，换碟片
    }
    dfs(i + 1, now, s, sum);//不录歌曲
}

int main() {
    scanf("%d%d%d", &n, &t, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    dfs(1, 0, 1, 0);//初始
    printf("%d\n", ans);
    return 0;
}