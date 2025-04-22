#include <iostream>
using namespace std;

class point {
    int x;
    int y;
public:
    point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }
};

int main() {
    point *a = new point(1, 2);

    return 0;
}