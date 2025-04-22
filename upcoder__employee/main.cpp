#include <iostream>
#include <string>
using namespace std;

class employee {
    int id;
    string firstName;
    string lastName;
    double salary;
public:
    employee() {
        id = 0;
        firstName = "none";
        lastName = "none";
        salary = 0;
    }
    employee(int _id, string _firstName, string _lastName, double _salary) {
        id = _id;
        firstName = _firstName;
        lastName = _lastName;
        salary = _salary;
    }
    int getID() {
        return id;
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    string getName() {
        return firstName + " " + lastName;
    }
    double getSalary() {
        return salary;
    }
    void setSalary(double _salary) {
        salary = _salary;
    }
    double getAnnualSalary() {
        return 12 * salary;
    }
    void raiseSalary(double percent) {
        salary += percent;
    }
    void toString() {
        cout << "Employee[id=" + to_string(id) + ",name=" + getName() + to_string(salary);
    }
    friend double operator++(employee arg) {
        arg.raiseSalary((arg.salary*0.1));
        return arg.salary;
    }
    friend double operator--(employee arg) {
        arg.raiseSalary((arg.salary*(-0.1)));
        return arg.salary;
    }
    friend bool operator>(employee arg_1, employee arg_2) {
        return arg_1.getAnnualSalary() > arg_2.getAnnualSalary();
    }
    friend bool operator<(employee arg_1, employee arg_2) {
        return !(arg_1 > arg_2);
    }
    friend bool operator==(employee arg_1, employee arg_2) {
        return !(arg_1 > arg_2 || arg_1 < arg_2);
    }
    friend bool operator!=(employee arg_1, employee arg_2) {
        return !(arg_1==arg_2);
    }
};

int main() {

}