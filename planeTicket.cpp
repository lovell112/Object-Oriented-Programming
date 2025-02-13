#include <iostream>
using namespace std;

struct dateTime{
    int day;
    int moonth;
    int year;
};

class planeTicket {
    protected:
        string name;
        dateTime date;
        int ticketPrice;
    public:
        planeTicket(){
            name = "";
            date.day = 0;
            date.moonth = 0;
            date.year = 0;
            ticketPrice = 0;
        }
        planeTicket(string n, int dd, int mm, int yyyy, int tp){
            name = n;
            date.day = dd;
            date.moonth = mm;
            date.year = yyyy;
            ticketPrice = tp;
        }
        void setName(string newName){
            name = newName;
        }
        void setDate(int dd, int mm, int yyyy){
            date.day = dd;
            date.moonth = mm;
            date.year = yyyy;
        }
        void setTicketPrice(int tp){
            ticketPrice = tp;
        }
        const string& getName() const {
            return name;
        }
        const dateTime& getDate() const {
            return date;
        }
        const int& getTicketPrice() const {
            return ticketPrice;
        }
};

class person {
    protected:
        string name;
        int age;
        string gender;
    public:
        person(){
            name = "";
            age = 0;
            gender = "";
        }
        person(string n, int a, string g){
            name = n;
            age = a;
            gender = g;
        }
        void setName(string newName){
            name = newName;
        }
        void setAge(int newAge){
            age = newAge;
        }
        void setGender(string newGender){
            gender = newGender;
        }
        const string& getName() const {
            return name;
        }
        const int& getAge() const {
            return age;
        }
        const string& getGender() const {
            return gender;
        }
};

class passenger : public person {
    private:
        planeTicket ticket;
        int numberTicket;
    public:
        passenger(string n, int a, string g, string nameTicket, int dd, int mm, int yyyy, int price, int number) : person(n, a, g){
            ticket.setName(nameTicket);
            ticket.setDate(dd, mm, yyyy);
            ticket.setTicketPrice(price);
            numberTicket = number;
        }
        passenger(){
            ticket.setName("");
            ticket.setDate(0, 0, 0);
            ticket.setTicketPrice(0);
            numberTicket = 0;
        }
        const int& getNumberTicket() const {
            return numberTicket;
        }
        const planeTicket& getTicket() const {
            return ticket;
        }
        void enterData(){
            getline(cin, name);
            cin >> age;
            cin.ignore();
            getline(cin, gender);
            string nameTicket; getline(cin, nameTicket); ticket.setName(nameTicket);
            int dd; cin >> dd;
            int mm; cin >> mm;
            int yyyy; cin >> yyyy;
            ticket.setDate(dd, mm, yyyy);
            int price; cin >> price; ticket.setTicketPrice(price);
            cin >> numberTicket;
        }
};

int main(){
    int numberPassenger; cin >> numberPassenger;
    cin.ignore();
    passenger* user = new passenger[numberPassenger];
    for (int i = 0; i < numberPassenger; i++){
        if(i == 0) cout << "Enter the " << i + 1 << "st : " << endl; 
        else if(i == 1) cout << "Enter the " << i + 1 << "nd : " << endl; 
        else if(i == 2) cout << "Enter the " << i + 1 << "rd : " << endl; 
        else cout << "Enter the " << i + 1 << "th : " << endl;
        user[i].enterData();
    }
    for(int i = 0; i < numberPassenger; i++){
        if(i == 0) cout << "The " << i + 1 << "st : "; 
        else if(i == 1) cout << "The " << i + 1 << "nd : "; 
        else if(i == 2) cout << "The " << i + 1 << "rd : "; 
        else cout << "The " << i + 1 << "th : ";
        cout << user[i].getName() << " needs to pay : " << user[i].getTicket().getTicketPrice() * user[i].getNumberTicket() << "$" << endl;
    }
    delete[] user;
    return 0;
}