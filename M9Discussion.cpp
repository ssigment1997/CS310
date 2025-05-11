#include <iostream>
using namespace std;

class Soda {
public:
    void showBrand() {
        cout << "This is a soda." << endl;
    }
};

class Sprite : public Soda {
public:
    void displayInfo();  // Function declared
};

void Sprite::displaInfo() {  // Typo: should be displayInfo
    cout << "This is Sprite." << endl;
}

class Pepsi : public Soda {
public:
    printInfo() {  // error: Missing return type
        cout << "This is Pepsi." << endl;
    }
};

int main() {
    Sprite s;
    Pepsi p;

    s.displayInfo();  // Won’t link due to typo
    p.printInfo();    // Won’t compile due to missing return type

    return 0;
}
