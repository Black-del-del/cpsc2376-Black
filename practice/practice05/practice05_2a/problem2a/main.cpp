#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Vector to store the numbers
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Calculate the sum using std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // Calculate the product using std::accumulate
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    std::cout << "Sum of elements: " << sum << std::endl;
    std::cout << "Product of elements: " << product << std::endl;

    return 0;
}
