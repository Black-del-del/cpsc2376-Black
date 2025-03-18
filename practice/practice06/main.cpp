#include <iostream>
#include <limits>
#include "fraction.h"
#include "mixedfraction.h"
#include "mixedfraction.cpp"
#include "fraction.cpp"

void clearFraction(Fraction& currentFraction) {
    currentFraction = Fraction();  // Reset to 0/1
}

void clearInputStream() {
    std::cin.clear();  // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
}

int main() {
    Fraction currentFraction;
    int choice;

    do {
        std::cout << "Current Fraction: " << currentFraction << "\n";
        std::cout << "\nOptions:\n";
        std::cout << "1. Enter a fraction manually\n";
        std::cout << "2. Add a fraction\n";
        std::cout << "3. Subtract a fraction\n";
        std::cout << "4. Multiply by a fraction\n";
        std::cout << "5. Divide by a fraction\n";
        std::cout << "6. Display as Mixed Fraction\n";
        std::cout << "7. Clear Fraction\n";
        std::cout << "8. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
            clearInputStream();
            continue;
        }

        switch (choice) {
            case 1: {
                int num, den;
                std::cout << "Enter numerator: ";
                std::cin >> num;
                std::cout << "Enter denominator: ";
                std::cin >> den;
                if (std::cin.fail() || den == 0) {
                    std::cerr << "Invalid input. Denominator cannot be zero.\n";
                    clearInputStream();
                    break;
                }
                try {
                    currentFraction = Fraction(num, den);
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }

            case 2: {
                int num, den;
                std::cout << "Enter numerator of the fraction to add: ";
                std::cin >> num;
                std::cout << "Enter denominator of the fraction to add: ";
                std::cin >> den;
                if (std::cin.fail() || den == 0) {
                    std::cerr << "Invalid input. Denominator cannot be zero.\n";
                    clearInputStream();
                    break;
                }
                try {
                    Fraction otherFraction(num, den);
                    currentFraction = currentFraction + otherFraction;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }

            case 3: {
                int num, den;
                std::cout << "Enter numerator of the fraction to subtract: ";
                std::cin >> num;
                std::cout << "Enter denominator of the fraction to subtract: ";
                std::cin >> den;
                if (std::cin.fail() || den == 0) {
                    std::cerr << "Invalid input. Denominator cannot be zero.\n";
                    clearInputStream();
                    break;
                }
                try {
                    Fraction otherFraction(num, den);
                    currentFraction = currentFraction - otherFraction;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }

            case 4: {
                int num, den;
                std::cout << "Enter numerator of the fraction to multiply: ";
                std::cin >> num;
                std::cout << "Enter denominator of the fraction to multiply: ";
                std::cin >> den;
                if (std::cin.fail() || den == 0) {
                    std::cerr << "Invalid input. Denominator cannot be zero.\n";
                    clearInputStream();
                    break;
                }
                try {
                    Fraction otherFraction(num, den);
                    currentFraction = currentFraction * otherFraction;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }

            case 5: {
                int num, den;
                std::cout << "Enter numerator of the fraction to divide by: ";
                std::cin >> num;
                std::cout << "Enter denominator of the fraction to divide by: ";
                std::cin >> den;
                if (std::cin.fail() || den == 0) {
                    std::cerr << "Invalid input. Denominator cannot be zero.\n";
                    clearInputStream();
                    break;
                }
                try {
                    Fraction otherFraction(num, den);
                    currentFraction = currentFraction / otherFraction;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            }

            case 6: {
                auto mixed = MixedFraction(currentFraction);
                std::cout << "Mixed Fraction: " << mixed << "\n";
                break;
            }

            case 7:
                clearFraction(currentFraction);
                break;

            case 8:
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 8);

    return 0;
}