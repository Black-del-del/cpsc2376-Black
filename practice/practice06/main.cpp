#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

using namespace std;

int main() {
    Fraction currentFraction; // Initial fraction is 0/1

    while (true) {
        cout << "Current Fraction: " << currentFraction << endl;
        cout << "Options:\n";
        cout << "1. Enter a fraction manually\n";
        cout << "2. Add a fraction\n";
        cout << "3. Subtract a fraction\n";
        cout << "4. Multiply by a fraction\n";
        cout << "5. Divide by a fraction\n";
        cout << "6. Display as Mixed Fraction\n";
        cout << "7. Clear Fraction\n";
        cout << "8. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int num, den;
            cout << "Enter numerator and denominator: ";
            cin >> num >> den;
            try {
                currentFraction.setNumerator(num);
                currentFraction.setDenominator(den);
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        } else if (choice >= 2 && choice <= 5) {
            int num, den;
            cout << "Enter fraction to operate with (numerator denominator): ";
            cin >> num >> den;
            try {
                Fraction inputFraction(num, den);
                if (choice == 2) {
                    currentFraction = currentFraction + inputFraction;
                } else if (choice == 3) {
                    currentFraction = currentFraction - inputFraction;
                } else if (choice == 4) {
                    currentFraction = currentFraction * inputFraction;
                } else if (choice == 5) {
                    currentFraction = currentFraction / inputFraction;
                }
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        } else if (choice == 6) {
            MixedFraction mixed(currentFraction);
            cout << "Mixed Fraction: " << mixed << endl;
        } else if (choice == 7) {
            currentFraction = Fraction(); // Reset to 0/1
        } else if (choice == 8) {
            break;
        }
    }

    return 0;
}
