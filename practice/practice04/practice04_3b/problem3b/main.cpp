#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> textHistory;
    std::string currentText = ""; 
    int choice;

    while (true) {
        std::cout << "\n1. Add Text\n";
        std::cout << "2. Undo Last Edit\n";
        std::cout << "3. Show Content\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character left by std::cin
        
        if (choice == 1) { 
            std::string newText;
            std::cout << "Enter text: ";
            std::getline(std::cin, newText);
            textHistory.push_back(currentText);
            currentText += newText;
        }
        else if (choice == 2) {
            if (!textHistory.empty()) {
                currentText = textHistory.back(); // Revert to the previous state
                textHistory.pop_back(); // Remove the last edit history
                std::cout << "Undo successful!\n";
            } else {
                std::cout << "No edits to undo.\n";
            }
        }
        else if (choice == 3) {
            std::cout << "Current Content: " << currentText << std::endl;
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
