#include <iostream>
using namespace std;

const int service_charges_1 = 40;
const int service_charges_2 = 70;

int main() {
    int income;
    int consulting_time_1;
    int consulting_time_2;
    int hourly_rate_1; 
    int hourly_rate_2;
    int billing_1;
    int billing_2; // Added this

    cout << "Enter consulting time 1: ";
    cin >> consulting_time_1;
    cout << endl;
  
    cout << "Enter hourly rate 1: ";
    cin >> hourly_rate_1;
    cout << endl;
  
    cout << "Enter consulting time 2: ";
    cin >> consulting_time_2;
    cout << endl;

    cout << "Enter hourly rate 2: ";
    cin >> hourly_rate_2;
    cout << endl; 
    
    cout << "Enter your income: ";
    cin >> income;
    cout << endl; 
  
    billing_1 = service_charges_1 * hourly_rate_1; 
    billing_2 = service_charges_2 * hourly_rate_2;

    if (income <= 25000) {
        if (consulting_time_1 <= 30) {
            cout << "The billing for option a is: ";
            cout << billing_1 << endl;
        } else {
            cout << "There are no charges for option a." << endl;
        }
    }

    if (consulting_time_2 <= 20) {
        cout << "The billing for option b is: ";
        cout << billing_2 << endl; 
    } else {
        cout << "There are no charges for option b." << endl;
    }

    return 0;
}
