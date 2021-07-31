#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);
    int n, start, end;
    cin >> n >> start >> end;
    start--, end--;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
                a[i][j] = 0x3c3c3c3c;
        }
    for (int k = 0; k < n; k++) // make sure that k is on the outside!
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] + a[j][k] < a[i][k])
                    a[i][k] = a[i][j] + a[j][k];
    cout << a[start][end] << endl;
}