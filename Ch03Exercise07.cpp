#include <iostream>
#include <iomanip> // Needed for setprecision

using namespace std;

int main()
{
    int netBalance;
    int payment;
    double interestRatePerMonth; // Should be double if it's a rate
    int d1;
    int d2;

    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "Enter the netBalance: ";
    cin >> netBalance;
    cout << endl;

    cout << "Enter the payment: ";
    cin >> payment;
    cout << endl;

    cout << "Enter the interest rate per month: ";
    cin >> interestRatePerMonth;
    cout << endl;

    cout << "Enter d1: ";
    cin >> d1;
    cout << endl;

    cout << "Enter d2: ";
    cin >> d2;
    cout << endl;

    // Use floating point division to ensure accurate interest calculation
    double interest = ((netBalance * d1) - (payment * d2)) / static_cast<double>(d1) * interestRatePerMonth;

    cout << "The interest is: $" << interest << endl;

    return 0;
}

