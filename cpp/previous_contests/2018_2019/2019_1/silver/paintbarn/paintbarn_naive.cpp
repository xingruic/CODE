#include <bits/stdc++.h>
using namespace std;
int n, k;
int barn[1001][1001];
int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    memset(barn, 0, sizeof(barn));
    cin >> n >> k;
    int x1, x2, y1, y2;
    for (int t = 0; t < n; t++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                barn[i][j]++;
            }
        }
    }
    int area = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (min(barn[i][j], min(barn[i + 1][j], min(barn[i][j + 1], barn[i + 1][j + 1]))) == k)
                area++;
        }
    }
    cout << area << endl;
}