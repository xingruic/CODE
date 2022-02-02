#include<bits/stdc++.h>
using namespace std;
int t;
int faces[11][2][5];
int z[5]; // used for storing the third dice
int sum_x, sum_y;
int sum_z_x, sum_z_y;
int cnt = 0;
int main() {
    cin >> t;
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 4; k++)
                cin >> faces[i][j][k];
            sort(faces[i][j] + 1, faces[i][j] + 5);
        }
    for (int i = 1; i <= t; i++) {
        sum_x = 0, sum_y = 0;
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                if (faces[i][1][j] > faces[i][2][k]) sum_x++;
                if (faces[i][2][j] > faces[i][1][k]) sum_y++;
            }
        }
        bool x_beats_y = sum_x > sum_y;
        bool brk = 0;
        // only 10000 possible cases for z, we can try them all!
        for (int a = 1; a <= 10; a++) {
            for (int b = 1; b <= 10; b++) {
                for (int c = 1; c <= 10; c++) {
                    for (int d = 1; d <= 10; d++) {
                        sum_z_x = 0, sum_z_y = 0;
                        sum_x = 0, sum_y = 0;
                        z[1] = a, z[2] = b, z[3] = c, z[4] = d;
                        for (int j = 1; j <= 4; j++) {
                            for (int k = 1; k <= 4; k++) {
                                if (z[j] > faces[i][1][k]) sum_z_x++;
                                if (faces[i][1][j] > z[k]) sum_x++;
                                if (z[j] > faces[i][2][k]) sum_z_y++;
                                if (faces[i][2][j] > z[k]) sum_y++;
                            }
                        }

                        if (sum_z_x > sum_x) {
                            if (x_beats_y) {
                                if (sum_z_y < sum_y) {
                                    cout << "yes" << endl;
                                    brk = 1;
                                    break;
                                }
                            }
                        }
                        if (sum_z_y > sum_y) {
                            if (!x_beats_y) {
                                if (sum_z_x < sum_x) {
                                    cout << "yes" << endl;
                                    brk = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (brk) break;
                }
                if (brk) break;
            }
            if (brk) break;
        }
        if (brk) continue;
        cout << "no" << endl;
    }
}