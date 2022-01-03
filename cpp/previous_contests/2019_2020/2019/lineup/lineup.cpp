#include<bits/stdc++.h>
using namespace std;
int n;
bool beside[9][9]; // 1-8, ordered Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, and Sue.
string names[9] = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
int len[9] = { 0,6,9,7,8,5,4,5,3 };
int toNum(string t) {
    int x;
    if (t[0] == 'S') x = 7;
    else {
        if (t[1] == 'u') x = 2;
        else if (t[1] == 'l') x = 6;
        else {
            if (t[2] == 's') x = 1;
            else if (t[2] == 'a') x = 4;
            else if (t[2] == 't') x = 6;
            else {
                if (t[3] == 'i') x = 3;
                else x = 5;
            }
        }
    }
    return x;
}
int main() {
    cin >> n;
    string t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        int x = toNum(t);
        int xx = toNum(t.substr(len[x] + 23));
        beside[x][xx] = beside[xx][x] = 1;
    }
    int shuffle[9] = { 0,1,2,3,4,5,6,7,8 };
    while (next_permutation(shuffle + 1, shuffle + 9)) {
        for (int i = 1; i <= 9; i++) {

        }
    }
}