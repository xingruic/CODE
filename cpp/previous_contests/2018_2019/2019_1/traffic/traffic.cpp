#include<bits/stdc++.h>
using namespace std;
int n;
struct seg {
    bool st = 0; // st=state,0=off,1=on;
    bool none = 0; // 1=none,0=look at st for on/off
    int min;
    int max;
}road[101];
int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    cin >> n;
    {
        string st; // the state of that segment
        for (int i = 1; i <= n; i++) {
            cin >> st >> road[i].min >> road[i].max;
            if (st == "on") road[i].st = 1;
            else if (st == "none") road[i].none = 1;
            // each segment is initialized to off
        }
    }
    int high, low;
    for (int i = n; i > 0; i--) {
        if (road[i].none) high = road[i].max, low = road[i].min;
        else if (!road[i].st) high += road[i].max, low += road[i].min;
        else {
            high -= road[i].min, low -= road[i].max;
            low = max(low, 0);
        }
    }
    cout << low << ' ' << high << endl;
    for (int i = 1; i <= n; i++) {
        if (road[i].none) high = road[i].max, low = road[i].min;
        else if (road[i].st) high += road[i].max, low += road[i].min;
        else {
            high -= road[i].min, low -= road[i].max;
            low = max(low, 0);
        }
    }
    cout << low << ' ' << high << endl;
}