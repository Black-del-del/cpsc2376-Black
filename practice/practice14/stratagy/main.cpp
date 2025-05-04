#include <iostream>
#include <memory>
#include <string>

#include "TextFilterStrategy.h"
#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "RemoveVowelsFilter.h"
#include "CensorBadWordsFilter.h"

void printMenu() {
    std::cout << "\nChoose a filter strategy:\n"
              << "1. Reverse\n"
              << "2. Uppercase\n"
              << "3. Remove Vowels\n"
              << "4. Censor Bad Words\n"
              << "5. Exit\n"
              << "Enter your choice: ";
}

std::unique_ptr<TextFilterStrategy> getStrategy(int choice) {
    switch (choice) {
        case 1: return std::make_unique<ReverseFilter>();
        case 2: return std::make_unique<UppercaseFilter>();
        case 3: return std::make_unique<RemoveVowelsFilter>();
        case 4: return std::make_unique<CensorBadWordsFilter>();
        default: return nullptr;
    }
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // flush newline

        if (choice == 5) break;

        auto strategy = getStrategy(choice);
        if (strategy) {
            std::string result = strategy->apply(input);
            std::cout << "Filtered Result: " << result << "\n";
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
