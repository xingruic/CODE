#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int win, ws = -1;
        int a, b;
        for(int i=1; i<=n; i++)
        {
            cin >> a >> b;
            if (a <= 10 && b > ws)
                ws = b, win = i;
        }
        cout << win << endl;
    }
}