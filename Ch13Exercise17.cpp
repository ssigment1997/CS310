#include <iostream>
#include <random>

int main() {
    
    std::random_device rd;

    // This is the random number generator engine
    std::mt19937 gen(rd());

    // distribution for real numbers between 10 and 100
    std::uniform_real_distribution<> dis(10.0, 100.0);

    std::cout << "25 random real numbers between 10 and 100:\n";

    // Generate and print 25 numbers
    for (int i = 0; i < 25; ++i) {
        double number = dis(gen);
        std::cout << number << "\n";
    }

    return 0;
}
