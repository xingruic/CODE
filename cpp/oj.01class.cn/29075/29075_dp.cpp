#include<bits/stdc++.h>
using namespace std;
int n, m;
int stu[501]; // the time each student starts waiting
bool went[501]; // if the student went or not
int main() {
    freopen("29075.out", "w", stdout);
    memset(went, 0, sizeof(went));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> stu[i];
    sort(stu + 1, stu + 1 + n);
}