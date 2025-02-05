#include <iostream>
using namespace std;

class smartphone{
    public:
        smartphone(string b, string v, float s, int w){
            brand = b;
            version = v;
            size = s;
            warranty = w;
        }
        void start(){
            cout << "HELLO WORLD welcome to " << version << endl;
        }
        void call(){
            cout << "CALLLLLLLLL" << endl;
        }
        string getSmart(){
            return version;
        }
    private:
        string brand;
        string version;
        float size;
        int warranty;
};

class galaxyS : public smartphone{
    public:
        galaxyS(string b, string v, float s, int w) : smartphone(b, v, s, w){
            smartphone::start();
        }
        void openSPen(){
            cout << "Open S-Pen" << endl;
        }
        void openPS(){
            cout << "Open Google Play Store" << endl;
        }
};

class iphone : public smartphone{
    public:
        iphone(string b, string v, float s, int w) : smartphone(b, v, s, w){
            smartphone::start();
        }
        void confirmIdentity(){
            cout << "Facial recognition successful - Faceid" << endl;
        }
        void airdrop(){
            cout << "Data transmission successful - Airdrop" << endl;
        }
        void openAS(){
            cout << "Open App Store successful" << endl;
        }
};

int main(){
    galaxyS* samsungS21 = new galaxyS("Samsung", "Samsung Galaxy S21", 6.5, 2);
    iphone* iphone16 = new iphone("Apple", "Iphone 16", 6, 2);

    cout << endl;
    cout << "Using " << samsungS21->getSmart() << endl;

    samsungS21->call();
    samsungS21->openPS();
    samsungS21->openSPen();

    cout << endl;
    cout << "Using " << iphone16->getSmart() << endl;

    iphone16->call();
    iphone16->airdrop();
    iphone16->openAS();
    iphone16->confirmIdentity();

    delete samsungS21;
    delete iphone16;
    return 0;
}