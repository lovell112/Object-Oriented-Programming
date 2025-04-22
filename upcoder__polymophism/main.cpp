#include <iostream>
using namespace std;

class Geomatry {
public:
    virtual float Perimeter() = 0;
};

class Rectangle : public Geomatry {
    float length, width;
public:
    Rectangle(float _length, float _width) {
        length = _length;
        width = _width;
    }
    virtual float Perimeter() {
        return 2*(length+width);
    }
    friend istream& operator>>(istream& is, Rectangle& param) {
        is >> param.length >> param.width;
        return is;
    }
    friend ostream& operator<<(ostream& os, Rectangle& param) {
        os << param.length << param.width;
        return os;
    }
};

class Square : public Rectangle {
    float a;
public:
    Square(float a) : Rectangle(a, a){}
    float Perimeter() override {
        return a * 4;
    }
    friend istream& operator>>(istream& is, Square& param) {
        is >> param.a;
        return is;
    }
    friend ostream& operator<<(ostream& os, Square& param) {
        os << param.Perimeter();
        return os;
    }
};


int main() {
    Geomatry* a[];
}