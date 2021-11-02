#include<bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int out = 1;
    int k = 0;
    for (;;out++) {
        for (int i = 0; i < a.size(); i++) {
            if (k == b.size()) break;
            if (a[i] == b[k]) k++;
        }
        if (k == b.size())break;
    }
    cout << out << endl;
}