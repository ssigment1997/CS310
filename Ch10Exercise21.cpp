#include <iostream>
#include <iomanip>
using namespace std;

class bankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate; // Stored as decimal (e.g., 0.05 for 5%)

    static int nextAccountNumber;

public:
    // Constructor
    bankAccount() {
        accountNumber = ++nextAccountNumber;
        name = "";
        accountType = "checking";
        balance = 0.0;
        interestRate = 0.0;
    }

    // Set account data
    void setAccount(string accName, string type, double initialBalance, double rate) {
        name = accName;
        accountType = type;
        balance = initialBalance;
        interestRate = rate;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount.\n";
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Invalid or insufficient funds.\n";
    }

    // Apply interest
    void applyInterest() {
        balance += (balance * interestRate);
    }

    // Display account info
    void display() const {
        cout << fixed << setprecision(2);
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name   : " << name << endl;
        cout << "Account Type  : " << accountType << endl;
        cout << "Balance       : $" << balance << endl;
        cout << "Interest Rate : " << interestRate * 100 << "%" << endl << endl;
    }
};

// Static member initialization
int bankAccount::nextAccountNumber = 1000;

int main() {
    const int MAX_CUSTOMERS = 10;
    bankAccount customers[MAX_CUSTOMERS];

    // Customer 1: Benjamin Cherelus
    customers[0].setAccount("Benjamin Cherelus", "saving", 1500.0, 0.04);
    
    // Customer 2: Example second customer
    customers[1].setAccount("Bob Smith", "checking", 800.0, 0.01);

    // Transactions
    customers[0].deposit(300);        // Benjamin deposits $300
    customers[1].withdraw(200);       // Bob withdraws $200
    customers[0].applyInterest();     // Apply interest to Benjamin's account

    // Display info
    for (int i = 0; i < 2; ++i) {
        cout << "Customer " << (i + 1) << " Info:\n";
        customers[i].display();
    }

    return 0;
}
