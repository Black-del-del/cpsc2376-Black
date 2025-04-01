#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f};   // Amount of red potion in mL
    float bluePotion{0.0f};  // Amount of blue potion in mL
    float* flask{nullptr};   // Pointer to the selected potion

    while (true) {
        std::string choice;
        std::cout << "Which potion to add liquid to? (Red/Blue, or type 'Done' to exit): ";
        std::cin >> choice;

        if (choice == "Done") {
            break;
        } else if (choice == "Red") {
            flask = &redPotion;
        } else if (choice == "Blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Invalid choice! Please enter 'Red' or 'Blue'.\n";
            continue;
        }

        float amount;
        std::cout << "Enter amount to add (mL): ";
        std::cin >> amount;

        if (amount < 0) {
            std::cout << "Amount cannot be negative!\n";
            continue;
        }

        *flask += amount;

        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n";
    }

    return 0;
}
