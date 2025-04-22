#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class bankAccount {
    string ID;
    string CustomerName;
    string IDCardNumber;
    double Balance;
    double WithdrawLimit;
public:
    bankAccount(string _ID = "000000", string _CustomerName = "No name", string _IDCardNumber = "xxx", double _Balance = 0) {
        ID = _ID;
        CustomerName = _CustomerName;
        IDCardNumber = _IDCardNumber;
        Balance = _Balance;
    }

    string getID(){return ID;}
    string getCustomerName(){return CustomerName;}
    string getIDCardNumber(){return IDCardNumber;}
    double getBalance(){return Balance;}
    double getWithdrawLimit(){return WithdrawLimit;}

    void setID(string _ID){ID = _ID;}
    void setCustomerName(string _CustomerName){CustomerName = _CustomerName;}
    void setIDCardNumer(string _IDCardNumber){IDCardNumber = _IDCardNumber;}
    void setBalance(double _Balance){Balance = _Balance;}
    void setWithdrawLimit(double _WithdrawLimit){WithdrawLimit = _WithdrawLimit;}

    bool Withdraw(double withdrawmoney) {
        if (withdrawmoney<=Balance&&withdrawmoney<=WithdrawLimit)
            return 1;
        else
            return 0;
    }
    double deposit(double depositmoney) {
        Balance += depositmoney;
        return Balance;
    }
    string toString() {
        return "{" + ID + "}:{" + CustomerName + "}:{" + to_string((int)Balance) + "}";
    }
};

class checkingAccount : public bankAccount {
    double OverDraftLimit;
public:
    checkingAccount(string _ID = "000000", string _CustomerName = "No name", string _IDCardNumber = "xxx", double _Balance = 0, double _OverDraftLimit = 50000)
    : bankAccount(_ID, _CustomerName, _IDCardNumber, _Balance) {setWithdrawLimit(_OverDraftLimit+getBalance()); OverDraftLimit = _OverDraftLimit;}
    bool Withdraw(double withdrawmoney) {
        if (withdrawmoney <= getWithdrawLimit()){
            setBalance(getBalance()-withdrawmoney);
            return 1;
        }
        else
            return 0;
    }
};

class saveAccount : public bankAccount {
    double interestRate;
    double interestMoney;
public:
    saveAccount(string _ID = "000000", string _CustomerName = "No name", string _IDCardNumber = "xxx", double money = 0)
        : bankAccount(_ID, _CustomerName, _IDCardNumber, money) {
        setWithdrawLimit(getBalance());
        if (getBalance() < 0) {
            setBalance(0);
            interestRate = 0.0;
        }
        if (getBalance() < 1000000)
            interestRate = 0.1;
        else if (getBalance() >= 1000000 && getBalance() < 50000000)
            interestRate = 0.3;
        else if (getBalance() >= 50000000 && getBalance() < 200000000)
            interestRate = 0.5;
        else if (getBalance() >= 200000000 && getBalance() < 1000000000)
            interestRate = 1.0;
        else
            interestRate = 1.94;
        interestMoney = interestRate*getBalance();
    }
    double deposit(double depositmoney) {
        setBalance(getBalance()+depositmoney);
        if (getBalance() < 0) {
            setBalance(0);
            interestRate = 0.0;
            return getBalance();
        }
        if (getBalance() < 1000000)
            interestRate = 0.1;
        else if (getBalance() >= 1000000 && getBalance() < 50000000)
            interestRate = 0.3;
        else if (getBalance() >= 50000000 && getBalance() < 200000000)
            interestRate = 0.5;
        else if (getBalance() >= 200000000 && getBalance() < 1000000000)
            interestRate = 1.0;
        else
            interestRate = 1.94;
        setBalance(getBalance() + interestMoney);
        return getBalance();
    }
    bool Withdraw(double withdrawMoney) {
        if (withdrawMoney <= getBalance()) {
            setBalance(getBalance() - withdrawMoney);
            return 1;
        } else
            return 0;
    }
};

int main() {
    char type;
    cin >> type;
    if (type=='C') {
        string inputLine;
        cin.ignore();
        getline(cin, inputLine);
        stringstream ss(inputLine);
        string ID;
        string customerName;
        string IDCardNumber;
        double money; string strMoney;
        double overDraftLimit; string strOverDraftLimit;
        getline(ss, ID, '/');
        getline(ss, customerName, '/');
        getline(ss, IDCardNumber, '/');
        getline(ss, strMoney, '/'); money = stod(strMoney);
        getline(ss, strOverDraftLimit, '\n'); overDraftLimit = stod(strOverDraftLimit);
        double withdrawMoney;
        cin >> withdrawMoney;
        checkingAccount* account = new checkingAccount(ID, customerName, IDCardNumber, money, overDraftLimit);
        cout << account->toString() << endl;
        cout << (account->Withdraw(withdrawMoney) ? "Yes " + account->toString() : "No") << endl;
        cout << "Checking Account";
        delete account;
    } else if (type=='S') {
        string inputLine;
        cin.ignore();
        getline(cin, inputLine);
        stringstream ss(inputLine);
        string ID;
        string customerName;
        string IDCardNumber;
        double money; string strMoney;
        double withdrawMoney;
        getline(ss, ID, '/');
        getline(ss, customerName, '/');
        getline(ss, IDCardNumber, '/');
        getline(ss, strMoney, '\n');
        money = stod(strMoney);
        cin >> withdrawMoney;
        saveAccount* account = new saveAccount(ID, customerName, IDCardNumber, money);
        cout << account->toString() << endl;
        cout << (account->Withdraw(withdrawMoney)? "Yes " + account->toString() : "No") << endl;
        account->deposit(0);
        cout << account->toString();
    }
    return 0;
}