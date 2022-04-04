#include<bits/stdc++.h>
using namespace std;
bool adj[6][6] = {
    {0,1,1,0,0,1},
    {1,0,1,0,0,0},
    {1,1,0,1,1,0},
    {0,0,1,0,1,1},
    {0,0,1,1,0,0},
    {1,0,0,1,0,0}
};
bool been[6] = { 1 };
int n = 6;
int main() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int t = q.front();
        cout << t << ' ';
        q.pop();
        for (int i = 0; i < n; i++) {
            if (!been[i] && adj[t][i]) {
                been[i] = 1;
                q.push(i);
            }
        }
    }cout << endl;
}