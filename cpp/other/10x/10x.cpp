#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("10x.in", "r", stdin);
    freopen("10x.out", "w", stdout);
    string s = "0";
    while (s.size() > 0) {
        getline(cin, s);
        for (int i = 0; i < 10; i++) cout << s << endl;
    }
}