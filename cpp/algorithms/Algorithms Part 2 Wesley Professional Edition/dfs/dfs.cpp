#include<bits/stdc++.h>
using namespace std;
bool marked[6] = { 0 };
bool adj[6][6] = {
    {0,1,1,0,0,1},
    {1,0,1,0,0,0},
    {1,1,0,1,1,0},
    {0,0,1,0,1,1},
    {0,0,1,1,0,0},
    {1,0,0,1,0,0}
};
int n = 6;
void dfs(int x) {
    if (marked[x]) return;
    marked[x] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[x][i]) {
            cout << x << " -> " << i << endl;
            dfs(i);
        }
    }
    return;
}
int main() {
    dfs(0);
    cout << endl;
}