#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        s.clear();
        char c;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> c;
                if (c != '.')
                    s += c;
            }
        }
        cout << s << endl;
    }
}