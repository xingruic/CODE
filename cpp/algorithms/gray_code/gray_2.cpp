#include <bits/stdc++.h>
using namespace std;
string to_bin(int i, int bits)
{
    string bin = "";
    while (i > 0)
    {
        bin = (char)(i % 2 + '0') + bin;
        i /= 2;
    }
    while (bin.size() < bits)
    {
        bin = '0' + bin;
    }
    return bin;
}
char XOR(char a, char b)
{
    if (a == b)
        return '0';
    else
        return '1';
}
int main()
{
    int n;
    cin >> n;
    int num = n;
    n = pow(2, n);
    string a[n];
    string code[n];
    for (int i = 0; i < n; i++)
    {
        code[i] = "";
        a[i] = '0' + to_bin(i, num);
        // cout<<a[i]<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            code[i] += XOR(a[i][j - 1], a[i][j]);
        }
        cout << code[i] << endl;
    }
}