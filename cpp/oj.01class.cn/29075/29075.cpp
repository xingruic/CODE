#include<bits/stdc++.h>
using namespace std;
int n, m;
int stu[501]; // student's arrival time
map<int, int> arrive;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> stu[i];
    }
    sort(stu + 1, stu + 1 + n);
    int rn = -1;
    for (int i = 1; i <= n; i++) {
        if (stu[i] != rn) {
            rn = stu[i];
            arrive.insert({ rn,1 });
        }
        else {
            arrive[rn]++;
        }
    }
    int ans = 0;
    int t = stu[1];
    int start = t;
    while (t <= stu[n]) {
        for (int i = start; i <= t; i++) {
            auto it = arrive.find(i);
            if (it != arrive.end()) {
                ans += t - (it->second);
            }
        }
        start = t + 1;
        t += m;
    }
    if (t < stu[n] + m) {
        ans += t - arrive[stu[n]];
    }
    cout << ans << endl;
}