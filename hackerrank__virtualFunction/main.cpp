#include <iostream>
#include <vector>
using namespace std;

class person {
    string name;
    int age;
public:
    person() {
        name = "none";
        age = 0;
    }
    person(string _name, int _age) {
        name = _name;
        age = _age;
    }
    string getName() {
        return name;
    }
    void setName(string _name) {
        name = _name;
    }
    int getAge() {
        return age;
    }
    void setAge(int _age) {
        age = _age;
    }
};

class professor : public person {
    int publication;
    static int curID;
    int id = curID;
public:
    professor(){
        publication = 0;
        id = ++curID;
    }
    professor(string _name, int _age, int _publication) {
        setName(_name);
        setAge(_age);
        publication = _publication;
    }
    int getPublication() {
        return publication;
    }
    int getID() {
        return id;
    }
    void setPublication(int _publication) {
        publication = _publication;
    }
    void consoleScan() {
        string _name;
        int _age, _publication;
        cin >> _name >> _age >> _publication;
    }
    void consolePrint() {
        cout << getName() << " " << getAge() << " " << publication << " " << id << endl;
    }
};
int professor::curID = 0;

class student : public person {
    int marks[6];
    static int cur_ID;
    int id = cur_ID;
public:
    student() {
        for (int i = 0; i < 6; i++) marks[i] = 0;
        id = ++cur_ID;
    }
    student(string _name, int _age, int _marks[]) {
        setName(_name);
        setAge(_age);
        for (int i = 0; i < 6; i++) {
            marks[i] = _marks[i];
        }
    }
    int* getMarks() {
        return marks;
    }
    int totalMark() {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        return sum;
    }
    void consoleScan() {
        string _name;
        int _age, _marks[6];
        cin >> _name >> _age;
        for (int i = 0; i < 6; i++) {
            cin >> _marks[i];
        }
        setName(_name);
        setAge(_age);
        for (int i = 0; i < 6; i++) {
            marks[i] = _marks[i];
        }
    }
    void consolePrint() {
        cout << getName() << " " << getAge() << " " << totalMark() << id << endl;
    }
};
int student::cur_ID = 0;

int main() {
    int type;
    int n;
    cin >> n;
    int perList[n];
    for (int i = 0; i < n; i++) {
        if (type == 1) {
            perList[i].consoleScan();
        } else {

        }
    }
    while (cin >> type) {
        if (type == 1) {
            professor temp;
            temp.consoleScan();
            prof.push_back(temp);
        } else {
            student temp;
            temp.consoleScan();
            stu.push_back(temp);
        }
    }
    for (int i = 0; i < prof.size(); i++) {
        prof[i].consolePrint();
        stu[i].consolePrint();
    }
    return 0;
}