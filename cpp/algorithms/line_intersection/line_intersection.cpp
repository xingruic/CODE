// this algorithm uses the orientation of 3 points mentioned in ../point_orientation/point_orientation.cpp

#include<iostream>
using namespace std;
enum orient { ccw, cw, collin };
orient orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int v1 = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    if (!v1) return collin;
    if (v1 > 0) return cw;
    return ccw;
}
bool inter(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    orient o1 = orientation(x1, y1, x2, y2, x3, y3), o2 = orientation(x1, y1, x2, y2, x4, y4), o3 = orientation(x3, y3, x4, y4, x1, y1), o4 = orientation(x3, y3, x4, y4, x2, y2);
    if ((o1 != o2 && o3 != o4) || (o1 == o2 && o2 == o3 && o3 == o4)) return 1;
    return 0;
}
int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << inter(x1, y1, x2, y2, x3, y3, x4, y4) << endl;
}