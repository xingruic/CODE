#include <bits/stdc++.h>
using namespace std;
int t;
int a[100001];
int b[100001];
int ans[101];
int main()
{
    {
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
            memset(a, 0, sizeof(a));
            int n;
            cin >> n;
            for (int j = 1; j <= n; j++)
            {
                cin >> a[j];
            }
            int diff = 0; // difference between odd and even digits
            int _min = 0x7fffffff;
            bool f = 1;
            for (int j = 1; j <= n; j++)
            {
                _min = min(_min, a[j]);
                if (f)
                    diff += a[j];
                else
                    diff -= a[j];
                b[j] = a[j];
            }
            for (int k = diff; k <= _min; k++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (b[j] > k && b[j + 1] > k)
                        b[j]--, b[j + 1]--;
                }
                f = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (b[j] != k)
                    {
                        f = 1;
                        break;
                    }
                }
                if (f)
                    continue;
                int cnt = 0;
                for (int j = 1; j <= n; j++)
                {
                    cnt += a[j] - diff;
                }
                cout << cnt << endl;
                break;
            }
        }
    }
}