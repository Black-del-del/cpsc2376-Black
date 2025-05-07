#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <stdexcept>
=======
>>>>>>> ad889a9f7bd8d7da89cc24cd253407005d6089d9

class MathUtils {
public:
  static int sumRange(int start, int end) {
    int sum = 0;
<<<<<<< HEAD
    for (int i = start; i <= end; i++) { 
=======
    for (int i = start; i <= end; i++) { // Fixed: Include 'end'
>>>>>>> ad889a9f7bd8d7da89cc24cd253407005d6089d9
      sum += i;
    }
    return sum;
  }
<<<<<<< HEAD
  
  static bool containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) { 
      if (numbers[i] < 0) { 
=======

  static bool containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) { // Fixed: < instead of <=
      if (numbers[i] < 0) { // Fixed: Check for negative, not positive
>>>>>>> ad889a9f7bd8d7da89cc24cd253407005d6089d9
        return true;
      }
    }
    return false;
  }

  static int findMax(const std::vector<int>& numbers) {
<<<<<<< HEAD
    if (numbers.empty()) throw std::invalid_argument("Empty vector has no maximum"); 
    int maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) { 
      if (numbers[i] > maxVal) { 
=======
    if (numbers.empty()) return 0; // Optional: could throw exception
    int maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) { // Fixed: < instead of <=
      if (numbers[i] > maxVal) { // Fixed: > instead of >= to avoid unnecessary overwrite
>>>>>>> ad889a9f7bd8d7da89cc24cd253407005d6089d9
        maxVal = numbers[i];
      }
    }
    return maxVal;
  }
};

int main() {
  std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
  std::vector<int> values = {3, -1, 5, 7};
  std::cout << "Contains negative? " << (MathUtils::containsNegative(values) ? "Yes" : "No") << std::endl;
  std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
  return 0;
}
