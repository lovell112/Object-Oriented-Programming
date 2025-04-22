#include <iostream>
using namespace std;

int  main(){
    int a = 10;
    int* newa = new int(a);
    cout << &a << " " << newa << endl;

    delete newa;
    cout << newa;
    return 0;
}