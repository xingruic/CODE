#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            int cntg = 0, cnth = 0;
            string t = s.substr(j, i);
            for (char c : t) {
                if (c == 'G') cntg++;
                else cnth++;
            }
            if (cntg == 1 || cnth == 1) cnt++;
        }
    }
    cout << cnt << endl;
}