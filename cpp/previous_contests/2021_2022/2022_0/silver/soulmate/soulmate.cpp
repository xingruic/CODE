#include <bits/stdc++.h>
using namespace std;
int n;
int a, b;
int minop(const int &j)
{
    int t = b;
    int ret = 0;
    while (t != j)
    {
        if (t > j)
        {
            if (t % 2)
                t--, ret++;
            else if (t / 2 >= j)
                t /= 2, ret++;
            else
                t--, ret++;
        }
        else
        {
            return -1;
        }
    }
    return ret;
}
int main()
{
    cin >> n;
    int d;
    int mo, minsteps;
    while (n--)
    {
        d = 0;
        minsteps = 0x7fffffff;
        cin >> a >> b;
        for (int j = a;;)
        {
            if ((mo = minop(j)) != -1)
            {
                // cout << j << ' ' << b << ' ' << mo << endl;
                minsteps = min(minsteps, mo + d);
            }
            if (j == 1)
            {
                break;
            }
            else if (j % 2)
            {
                j = (j + 1) / 2;
                d += 2;
            }
            else
                j /= 2, d++;
        }

        cout << minsteps << endl;
    }
}