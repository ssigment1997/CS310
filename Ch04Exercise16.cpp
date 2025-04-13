#Student: Benjamin Cherelus
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

// Named constants for royalty calculations
const double FIXED_PAYMENT = 25000.0;
const double OPTION2_RATE = 0.125;
const double OPTION3_RATE_LOW = 0.10;
const double OPTION3_RATE_HIGH = 0.14;
const int THRESHOLD_COPIES = 4000;

int main() {
    double price, copies;
    double option1, option2, option3;
    int bestOption;

    // Input
    std::cout << "Enter the net price of each copy: ";
    std::cin >> price;
    std::cout << "Enter the estimated number of copies sold: ";
    std::cin >> copies;

    // Calculate royalties for each option
    option1 = FIXED_PAYMENT;
    option2 = OPTION2_RATE * price * copies;

    if (copies <= THRESHOLD_COPIES) {
        option3 = OPTION3_RATE_LOW * price * copies;
    } else {
        option3 = (THRESHOLD_COPIES * OPTION3_RATE_LOW * price) + 
                  ((copies - THRESHOLD_COPIES) * OPTION3_RATE_HIGH * price);
    }

    // Determine the best option
    if (option1 >= option2 && option1 >= option3) {
        bestOption = 1;
    } else if (option2 >= option3) {
        bestOption = 2;
    } else {
        bestOption = 3;
    }

    // Output results
    std::cout << "\nRoyalties under each option:\n";
    std::cout << "Option 1: $" << std::fixed << std::setprecision(2) << option1 << "\n";
    std::cout << "Option 2: $" << std::fixed << std::setprecision(2) << option2 << "\n";
    std::cout << "Option 3: $" << std::fixed << std::setprecision(2) << option3 << "\n\n";

    // Switch statement to display the best option
    switch(bestOption) {
        case 1:
            std::cout << "Best option: Option 1\n";
            break;
        case 2:
            std::cout << "Best option: Option 2\n";
            break;
        case 3:
            std::cout << "Best option: Option 3\n";
            break;
        default:
            std::cout << "Error in determining the best option.\n";
            break;
    }

    return 0;
}

