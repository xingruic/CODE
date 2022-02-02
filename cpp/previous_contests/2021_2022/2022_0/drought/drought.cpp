#include<bits/stdc++.h>
using namespace std;
int t;
int num[101];
vector<long long> cows[101];
int ans = 0x7fffffff;
int _hash(vector<long long> hunger) {
    long long sum = 1;
    for (int i = 0; i < hunger.size(); i++) {
        sum = sum * (hunger[i] + 1) + hunger[i];
    }
    return sum % 936557;
}
bool mem[936558];
void feed(vector<long long> hunger, int cnt = 0) {
    int hsh = _hash(hunger);
    if (mem[hsh]) return;
    else mem[hsh] = 1;
    bool go = 1;
    for (int i = 0; i < hunger.size() - 1; i++) {
        if (hunger[i] != hunger[i + 1]) {
            go = 0;
            break;
        }
    }
    if (go) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < hunger.size() - 1; i++) {
        if (hunger[i] > 0 && hunger[i + 1] > 0) {
            hunger[i]--, hunger[i + 1]--;
            feed(hunger, cnt + 2);
            hunger[i]++, hunger[i + 1]++;
        }
    }
    return;
}
int main() {
    memset(num, -1, sizeof(num));
    memset(mem, 0, sizeof(mem));
    cin >> t;
    long long tmp;
    for (int i = 1; i <= t; i++) {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++) {
            cin >> tmp;
            cows[i].push_back(tmp);
        }
    }
    for (int i = 1; i <= t; i++) {
        feed(cows[i]);
        if (ans == 0x7fffffff) cout << -1 << endl;
        else cout << ans << endl;
        ans = 0x7fffffff; // get ready for next test case
        memset(mem, 0, sizeof(mem));
    }
}