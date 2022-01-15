#include<bits/stdc++.h>
using namespace std;
int n, m;
int stu[501]; // the time each student starts waiting
bool went[501]; // if the student went or not
int ans[501][501]; // stores the answers for recursion
int solve(int i, int start) {
    if (i == n + 1)
        return 0;
    if (start < stu[i])
        return solve(i, stu[i]);
    if (ans[i][start - stu[i]] >= 0)
        return ans[i][start - stu[i]];
    int sum = 0, j = i;
    while (j <= n && stu[j] <= start)
        sum += stu[j++];
    int best = start * (j - i) - sum + solve(j, start + m);
    for (;j <= n;j++) {
        sum += stu[j];
        best = min(stu[j] * (j - i + 1) - sum + solve(j + 1, stu[j] + m), best);
    }
    return ans[i][start - stu[i]] = best;
}
int main() {
    memset(ans, -1, sizeof(ans));
    freopen("29075.out", "w", stdout);
    memset(went, 0, sizeof(went));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> stu[i];
    sort(stu + 1, stu + 1 + n); // sort the input so its easier to use
    // for (int i = 1; i <= n; i++) {
    //     cout << stu[i] << ' ';
    // }cout << endl;
    cout << solve(1, 0) << endl;
}