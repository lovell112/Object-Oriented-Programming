#include <iostream>
using namespace std;

class point {
    int size;
    float* points;
public:
    point() {
        size = 0;
        points = new float[1];
    }
    point(int s) {
        size = s;
        points = new float[size];
    }
    ~point() {
        delete[] points;
    }
    int getSize() {
        return size;
    }
    void setSize(int s) {
        size = s;
    }
    float* getPoints(int index) {
        return points+index;
    }
    float& operator[](int index) {
        return *getPoints(index);
    }
    friend istream& operator>>(istream& is, point& p) {
        is >> p.size;
        p.points = new float[p.size];
        for (int i = 0; i < p.size; i++) {
            cin >> p.points[i];
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, point p) {
        bool flag = 0;
        for (int i = 0; i < p.size; i++) {
            os << (flag?" ":"");
            os << p.points[i] << endl;
            flag = 1;
        }
        return os;
    }
    point operator=(point other) {
        size = other.size;
        other.points = new float[size];
        for (int i = 0; i < size; i++) {
            points[i] = other.points[i];
        }
        return *this;
    }
    float gpa() {
        float s = 0.0;
        for (int i = 0; i < size; i++) {
            s += points[i];
        }
        return s/size;
    }
};

class student {
    string fullName;
    string id;
    point points;
public:
    student() {
        string fullName = "None";
        id = "K00.00.00.00";
        for (int i = 0; i < points.getSize(); i++) {
            points[i] = 0;
        }
    }
    student(string _fullName, string _id, point _points) {
        fullName = _fullName;
        id = _id;
        points = _points;
    }
    friend istream& operator>>(istream& is, student& s) {
        cin.ignore();
        getline(is, s.fullName);
        is >> s.id;
        is >> s.points;
        return is;
    }
    friend ostream& operator<<(ostream& os, student s) {
        os << s.fullName << endl;
        os << s.id << endl;
        os << s.points.gpa();
        return os;
    }
};