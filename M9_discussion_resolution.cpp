#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Base class for all musical instruments
class instrument {
private:
    string brand;
    string model;
    float price;
    int year;

public:
    // Constructor
    instrument(string b, string m, float p, int y)
        : brand(b), model(m), price(p), year(y) {}

    // Getter for brand
    string getBrand() const {
        return brand;
    }

    // Public method to show details
    void showDetails() const {
        cout << brand << " " << model << " (" << year << ")" << endl;
        cout << "  Value: $" << price << endl;
    }
};

// Derived class for guitars
class guitar : public instrument {
private:
    string type_strings;
    int num_strings;

public:
    guitar(string b, string m, float p, int y, string strings, int count)
        : instrument(b, m, p, y), type_strings(strings), num_strings(count) {}

    void play() {
        cout << "  Playing " << num_strings << "-string " << getBrand() << " guitar" << endl;
        cout << "  Sounds good connected to the amp" << endl;
    }

    void tune() {
        cout << "  Tuned to EADGBE" << endl;
    }
};

// Derived class for pianos
class Piano : public instrument {
private:
    int num_keys;

public:
    Piano(string b, string m, float p, int y, int keys)
        : instrument(b, m, p, y), num_keys(keys) {}

    void play() {  // Fixed: added return type
        cout << "  Playing " << num_keys << "-key " << getBrand() << " piano" << endl;
        cout << "  Sounds good and using reverb" << endl;
    }

    void tune() {
        cout << "  Electric piano, digitally tuned" << endl;
    }
};

// Main program
int main() {
    guitar myguitar("PRS", "Custom 24", 1000.00, 2023, "Steel", 6);
    Piano myPiano("Roland", "FP-30X", 750.00, 2024, 88);

    cout << "\n\n  Inventory of my instruments" << endl;
    cout << "  ---------------------------" << endl;

    cout << "\n  My Guitar" << endl;
    cout << "  ---------------------------" << endl;
    myguitar.showDetails();
    myguitar.play();
    myguitar.tune();

    cout << "\n  My Piano" << endl;
    cout << "  ---------------------------" << endl;
    myPiano.showDetails();
    myPiano.play();
    myPiano.tune();

    cout << "\n  Press any key to continue..." << endl;
    (void)_getch();
    return 0;
}
