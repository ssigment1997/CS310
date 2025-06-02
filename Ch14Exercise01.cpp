#include <iostream>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

// Exception class for negative input
class negativeNumber : public exception {
public:
    const char* what() const noexcept override {
        return "Negative number entered.";
    }
};

// Exception class for non-numeric input
class nonNumber : public exception {
public:
    const char* what() const noexcept override {
        return "Non-numeric input entered.";
    }
};

// Function to check if a string is a number
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return !s.empty();
}

// Converts feet and inches to centimeters
double convertToCentimeters(int feet, int inches) {
    double totalInches = feet * 12 + inches;
    return totalInches * 2.54;
}

int main() {
    string feetStr, inchesStr;
    int feet, inches;
    bool valid = false;

    while (!valid) {
        try {
            cout << "Enter feet: ";
            cin >> feetStr;
            if (!isNumber(feetStr)) throw nonNumber();
            feet = stoi(feetStr);
            if (feet < 0) throw negativeNumber();

            cout << "Enter inches: ";
            cin >> inchesStr;
            if (!isNumber(inchesStr)) throw nonNumber();
            inches = stoi(inchesStr);
            if (inches < 0) throw negativeNumber();

            double centimeters = convertToCentimeters(feet, inches);
            cout << "Equivalent length in centimeters: " << centimeters << " cm" << endl;
            valid = true;
        }
        catch (const nonNumber& e) {
            cout << "Error: " << e.what() << " Please enter digits only.\n\n";
        }
        catch (const negativeNumber& e) {
            cout << "Error: " << e.what() << " Please enter non-negative values.\n\n";
        }
    }

    return 0;
}
