#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> 

int main() {
    std::vector<int> numbers;
    int num;
    int threshold;

    std::cout << "Enter integers (enter a non-digit character to stop):\n";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ask for the threshold value
    std::cout << "Enter the threshold value: ";
    std::cin >> threshold;

    int count = std::count_if(numbers.begin(), numbers.end(), [threshold](int n) {
        return n > threshold;
    });

    std::cout << "Number of elements greater than the threshold: " << count << std::endl;

    // Remove elements below the threshold using std::remove_if and a lambda
    auto new_end = std::remove_if(numbers.begin(), numbers.end(), [threshold](int n) {
        return n <= threshold;
    });

    // Resize the vector to the new size after removal
    numbers.erase(new_end, numbers.end());

    std::cout << "Modified list (values greater than threshold): ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
