#include <iostream>
#include <iomanip>
using namespace std;

class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    bankAccount(int accNum = 0, double bal = 0.0) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) { accountNumber = accNum; }
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    virtual void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
    }

    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << fixed << setprecision(2);
        cout << "Balance: $" << balance << endl;
    }
};

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharges;

public:
    checkingAccount(int accNum = 0, double bal = 0.0, double rate = 0.0, double minBal = 0.0, double charges = 0.0)
        : bankAccount(accNum, bal), interestRate(rate), minBalance(minBal), serviceCharges(charges) {}

    void setInterestRate(double rate) { interestRate = rate; }
    double getInterestRate() const { return interestRate; }

    void setMinBalance(double minBal) { minBalance = minBal; }
    double getMinBalance() const { return minBalance; }

    void setServiceCharges(double charges) { serviceCharges = charges; }
    double getServiceCharges() const { return serviceCharges; }

    void postInterest() {
        if (balance >= minBalance)
            balance += balance * interestRate;
    }

    bool isBelowMinBalance() const {
        return balance < minBalance;
    }

    void writeCheck(double amount) {
        withdraw(amount);
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            if (balance < minBalance)
                balance -= serviceCharges;
        }
    }

    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "Minimum Balance: $" << minBalance << endl;
        cout << "Service Charges: $" << serviceCharges << endl;
    }
};

class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    savingsAccount(int accNum = 0, double bal = 0.0, double rate = 0.0)
        : bankAccount(accNum, bal), interestRate(rate) {}

    void setInterestRate(double rate) { interestRate = rate; }
    double getInterestRate() const { return interestRate; }

    void postInterest() {
        balance += balance * interestRate;
    }

    void withdraw(double amount) override {
        if (amount <= balance)
            balance -= amount;
    }

    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

int main() {
    cout << "Checking Account Test:\n";
    checkingAccount ca(12345, 500.00, 0.01, 300.00, 25.00);
    ca.printAccountInfo();
    ca.deposit(200);
    ca.writeCheck(100);
    ca.postInterest();
    ca.printAccountInfo();

    cout << "\nSavings Account Test:\n";
    savingsAccount sa(67890, 1000.00, 0.03);
    sa.printAccountInfo();
    sa.deposit(500);
    sa.withdraw(300);
    sa.postInterest();
    sa.printAccountInfo();

    return 0;
}
