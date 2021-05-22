#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p;
    cin >> n >> p;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t[n] = {0}; // 特征值
    int f[n] = {0}; // 分数
    for (int i = 0; i < n; i++)
    {
        t[i] = a[i];
        int maxt = -0x80000000;
        for (int j = i - 1; j >= 0; j--)
        {
            maxt = max(maxt, t[j]);
        }
        if (i > 0)
            t[i] += maxt;
        cout << t[i] << endl;
        if (i == 0)
        {
            f[i] = t[i];
            cout << f[i] << endl
                 << endl;
            continue;
        }
        maxt = -0x80000000;
        for (int j = i - 1; j >= 0; j--)
        {
            if (t[j] + f[j] > maxt)
                maxt = t[j] + f[j];
        }
        f[i] = maxt;
        cout << f[i] << endl
             << endl;
    }
    int maxf = -0x80000000;
    for (int i = 0; i < n; i++)
    {
        maxf = max(maxf, f[i]);
    }
    cout << maxf % maxf << endl;
}