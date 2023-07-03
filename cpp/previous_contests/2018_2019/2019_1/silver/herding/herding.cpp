#include <bits/stdc++.h>
using namespace std;
int n;
int cows[5];
bool lmov = 0, rmov = 0;
int cowmax()
{
    if (lmov && cows[1] - cows[0] <= cows[n - 1] - cows[n - 2])
    {
        return cows[n - 1] - cows[1] - 1 - (n - 3);
    }
    else if (rmov)
    {
        return cows[n - 2] - cows[0] - 1 - (n - 3);
    }
    else
    {
        return cows[n - 1] - cows[1] - 1 - (n - 3);
    }
}
// finds the farthest space that the leftmost cow can move rightward to
int rightward()
{
    int i;
    for (i = n - 2; i > 0; i--)
    {
        if (cows[i + 1] - 1 != cows[i])
            return cows[i + 1] - 1 - cows[0];
    }
    return -1;
}
// like rightward(), but for rightmost cow
int leftward()
{
    int i;
    for (i = 1; i < n - 1; i++)
    {
        if (cows[i - 1] + 1 != cows[i])
            return cows[n - 1] - (cows[i - 1] + 1);
    }
    return -1;
}
int cowmin()
{
    int lw, rw, i;
    for (i = 0; (lw = leftward()) != -1 || (rw = rightward()) != -1; i++)
    {
        if (lw > rw)
        {
            cows[n - 1] -= lw;
        }
        else
        {
            cows[0] += rw;
        }
        sort(cows, cows + n);
    }
    return i;
}
int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cows[i];
    sort(cows, cows + n);
    lmov = rightward() != -1;
    rmov = leftward() != -1;
    cout << rightward() << ' ' << leftward() << endl;
    int cmax = cowmax();
    cout << cowmin() << endl
         << cmax << endl;
}