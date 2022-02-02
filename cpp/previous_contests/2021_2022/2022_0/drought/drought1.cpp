#include<bits/stdc++.h>
using namespace std;
int t;
int num[101];
vector<long long> cows[101];
int dp[936558]; // 936557 is a prime
int hash2cow[936558];
int _hash(vector<long long> v) {
    int sum = 1;
    for (int i = 0; i < v.size(); i++) {
        sum = sum * (v[i] + 1) + v[i];
    }
    return sum % 936557;
}
int main() {
    memset(dp, -1, sizeof(dp));
    memset(hash2cow, -1, sizeof(hash2cow));
    cin >> t;
    long long tmp;
    for (int i = 1; i <= t; i++) {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++) {
            cin >> tmp;
            cows[i].push_back(tmp);
        }
    }
    int ans = 0x7fffffff;
    for (int i = 1; i <= t; i++) {
        vector<long long> tmp = cows[i];
        int t = _hash(cows[i]);
        for (int j = 0; j < cows[i].size() - 1; j++) {
            if (tmp[j] > 0 && tmp[j + 1] > 0) {
                tmp[j]++, tmp[j + 1]++;
                int tt = _hash(tmp);
                dp[t] = dp[tt] + 2;
            }
        }
        bool flag = 1;
        for (int j = 0; j < cows[i].size() - 1; j++) {
            if (cows[i][j] != cows[i][j + 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) ans = min(ans, dp[t]);
        ans = 0x7fffffff;
        memset(dp, -1, sizeof(dp));
    }
}