#include <iostream>
#include <vector>
#include <iterator>
#include <limits>

int main() {
    std::vector<int> numbers;
    int num;
    char cont;

    // Take user input for integers
    std::cout << "Enter integers (enter a non-digit character to stop):\n";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Print numbers using iterators
    std::cout << "Numbers entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Find and print the sum of even numbers using iterators
    int sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            sum += *it;
        }
    }

    std::cout << "Sum of even numbers: " << sum << std::endl;

    return 0;
}
