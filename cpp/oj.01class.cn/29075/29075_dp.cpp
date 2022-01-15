#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
int stu[501]; // the time each student starts waiting
bool went[501]; // if the student went or not
int dp[501][501];
int main() {
    memset(dp, 0, sizeof(dp));
    freopen("problem_3294_test_cases/3.in", "r", stdin);
    freopen("29075.out", "w", stdout);
    memset(went, 0, sizeof(went));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> stu[i];
    sort(stu + 1, stu + 1 + n);
    for (int i = n; i >= 1; i--) {
        for (int start = n; start >= 0; start--) {
            if (start < stu[i]) {
                continue;
            }
            int sum = 0, j = i;
            while (j <= n && stu[j] <= start) sum += stu[j++];
            int best = start * (j - i) - sum + dp[j][start + m];
            for (;j <= n;j++) {
                sum += stu[j];
                best = min(stu[j] * (j - i + 1) - sum + dp[j + 1][stu[j] + m], best);
            }
            dp[i][start - stu[i]] = best;
        }
    }
    cout << dp[1][0] << endl;
}