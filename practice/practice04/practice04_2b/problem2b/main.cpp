#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
T findMax(T a, T b, T c) {
    return std::max({a, b, c});
}

int main() {
    int choice;
    
    std::cout << "Compare (1) Numbers or (2) Strings? ";
    std::cin >> choice;
    
    if (choice == 1) { // Compare numbers
        int num1, num2, num3;
        
        std::cout << "Enter first value: ";
        std::cin >> num1;
        std::cout << "Enter second value: ";
        std::cin >> num2;
        std::cout << "Enter third value: ";
        std::cin >> num3;
        
        int maxNum = findMax(num1, num2, num3);
        std::cout << "Max value: " << maxNum << std::endl;
    }
    else if (choice == 2) { // Compare strings
        std::string str1, str2, str3;
        
        std::cout << "Enter first value: ";
        std::cin >> str1;
        std::cout << "Enter second value: ";
        std::cin >> str2;
        std::cout << "Enter third value: ";
        std::cin >> str3;
        
        std::string maxStr = findMax(str1, str2, str3);
        std::cout << "Max value: " << maxStr << std::endl;
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
