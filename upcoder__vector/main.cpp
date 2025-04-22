#include <iostream>
using namespace std;

class vector {
    int x;
    int y;
public:
    vector() {
        x = 0;
        y = 0;
    }
    vector(int x0, int y0) {
        x = x0;
        y = y0;
    }
    void print() {
        cout << "(" << x << "," << y << ")" << endl;
    }
    vector operator-() {
        x = -x;
        y = -y;
        return *this;
    }
    int& operator[](int index) {
        return index==1?x:y;
    }
};

int main() {
    vector a;
    a.print();
    cout << "after" << endl;
    a = -a;
    a.print();
    a[1] = 2;
    cout << a[1];
    a.print();
    return 0;
}