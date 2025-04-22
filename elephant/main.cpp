#include <iostream>
using namespace std;

class elephant {
private:
    int age;
    float height;
    int root;
    bool flag;
public:
    void set(int a, float h, int s = 0) {
        age = a;
        height = h;
        root = s;
    }
    elephant() {
        age = 0;
        height = 0.0;
        root = 0;
    }
    void fater() {
        height++;
    }
    void order() {
        age++;
    }
    void print() {
        cout << "Im a " << ((root == 0) ? "Asia" : "Africa") << " Elephant, Im " << age << " year's old, weight " << height << "kg." << endl;
    }
    void trumpet() {
        if (age == 0 && height == 0.0 && root == 0) {
            cout << "Empty!" << endl;
        }
    }
};

int main() {
    elephant *obj1 = new elephant;
    elephant *obj2 = new elephant;
    obj1->set(5, 4.7);
    obj1->fater();
    obj1->order();
    cout << "After : ";
    obj1->print();
    obj1->fater();
    obj1->order();
    cout << "Before : ";
    obj1->print();
    cout << "object 2 is ";
    obj2->trumpet();
    return 0;
}