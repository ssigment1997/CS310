#include <iostream>

using namespace std;

const int F = 80; // Maximum allowed time

int main() {
    int a, b, c, d, e;

    // Input for four dishes
    cout << "Enter the number of minutes it takes to prepare Bianca's first dish: ";
    cin >> a;

    cout << "Enter the number of minutes it takes to prepare Bianca's second dish: ";
    cin >> b;

    cout << "Enter the number of minutes it takes to prepare Bianca's third dish: ";
    cin >> c;

    cout << "Enter the number of minutes it takes to prepare Bianca's fourth dish: ";
    cin >> d;

    // Calculate total preparation time
    e = a + b + c + d;

    // Conditional check
    if (e <= F) {
        cout << "You have made the dishes on time!" << endl;
    } else if (e > F) {
        cout << "This is exceeding the time limit!" << endl;
    }

      cout << "Your max amount of dishes is 4" << endl;
    return 0;


}

    



    

