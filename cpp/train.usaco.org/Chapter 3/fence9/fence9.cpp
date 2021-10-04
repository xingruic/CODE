/*
ID:xingrui1
TASK:fence9
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, p;
int main() {
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);
    cin >> n >> m >> p;
    // use pick's theorem backwards
    int area = p * m * 0.5;
    int b = p + 1 + __gcd(n, m) + __gcd(abs(n - p), m) - 1;
    printf("%d\n", (int)round(area + 1 - b * 0.5));
}