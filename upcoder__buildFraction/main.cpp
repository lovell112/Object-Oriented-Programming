#include <iostream>
using namespace std;

class fraction {
private:
    int num;
    int deno;
public:
    bool infinitive() {
        return deno==0?1:0;
    }
    fraction(int n = 0, int d = 1) {
        num = n;
        deno = d;
    }
    int getNumberator() {
        return num;
    }
    int getDenominator() {
        return deno;
    }
    void setNumberator(int n) {
        num = n;
    }
    void setDenominator(int d) {
        deno = d;
    }
    void inverse() {
        if (num == 0) {
            num = 0;
            deno = 1;
        }
        else {
            int temp = num;
            num = deno;
            deno = temp;
        }
    }
    void shink() {
        int a = num;
        int b = deno;
        while (b!=0) {
            int temp = a%b;
            a = b;
            b = temp;
        }
        num /= a;
        deno /= a;
    }
    friend istream& operator>>(istream& is, fraction& a) {
        int n, d;
        cin >> n >> d;
        a.setNumberator(n);
        a.setDenominator(d);
        return is;
    }
    friend ostream& operator<<(ostream& os, fraction a) {
        os << a.getNumberator() << "/" << a.getDenominator();
        return os;
    }
    friend fraction operator+(fraction arg1, fraction arg2) {
        fraction result(arg1.getNumberator()*arg2.getDenominator()+arg1.getDenominator()*arg2.getNumberator(), arg1.getDenominator()*arg2.getDenominator());
        result.shink();
        return result;
    }
    friend fraction operator-(fraction arg1, fraction arg2) {
        arg2.setNumberator(-arg2.getNumberator());
        return arg1 + arg2;
    }
    friend fraction operator*(fraction arg1, fraction arg2) {
        fraction result(arg1.getNumberator()*arg2.getNumberator(), arg1.getDenominator()*arg2.getDenominator());
        result.shink();
        return result;
    }
    friend fraction operator/(fraction arg1, fraction arg2) {
        arg2.inverse();
        return arg1 * arg2;
    }
};

int main() {
    fraction a;
    cin >> a;
    if (a.infinitive()) {
        cout << "Fraction is infinitive!";
        return 0;
    }
    cout << a << endl;
    cout << a.getNumberator() << endl;
    cout << a.getDenominator() << endl;
    fraction aInverse = a;
    aInverse.inverse();
    cout << aInverse << endl;
    a.shink();
    cout << a << endl;
    cout << a + aInverse;
    return 0;
}