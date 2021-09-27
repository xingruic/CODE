#include <iostream>
using namespace std;

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

int main() {
    int c = 0;
    while (1) {
        c = 0;
        switch ((c = getc(stdin))) {
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }

    }

    return 0;
}