#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    int a, b, c;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a + b >= 10 || b + c >= 10 || c + a >= 10)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}