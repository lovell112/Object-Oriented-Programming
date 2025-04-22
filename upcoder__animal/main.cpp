#include <iostream>
using namespace std;

class animal {
public:
    virtual void Eat() = 0;
    // {
    //     cout << "Animal eating ...\n";
    // }
};

class Elephant : public animal {
    void Eat() {
        animal::Eat();
        cout << "It's Elephant\n";
    }
};

class Lion : public animal {
public:
    void Eat() {
        animal::Eat();
        cout << "It's Lion\n";
    }
};

int main() {
    animal[2];
    Elephant a, b, c;
    animals[0] = a; animals[1] = b;
    for (int i = 0; i < 2; i++)
        animals[i];
    return 0;
}