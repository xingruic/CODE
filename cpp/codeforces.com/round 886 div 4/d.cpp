#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[200000];
int main()
{
    freopen("d.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int start = 0, end = n;
        bool cont = 1;
        int cnt = 0;
        while (cont)
        {
            cont = false;
            for (int i = start + 1; i < end; i++)
            {
                if (a[i] - a[i - 1] > k)
                {
                    cont = true;
                    cnt++;
                    if ((i - 1) * 2 >= n)
                    {
                        end = i;
                    }
                    else
                    {
                        start = i;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}