#include <iostream>
#include <vector>

class MathUtils {
public:
  // Fix: Include 'end' in the range, so loop must go to <= end
  static int sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
      sum += i;
    }
    return sum;
  }

  // Fixes:
  // 1. Use i < numbers.size() to avoid out-of-bounds.
  // 2. Check for numbers[i] < 0 (not > 0).
  static bool containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {
      if (numbers[i] < 0) {
        return true;
      }
    }
    return false;
  }

  // Fixes:
  // 1. Use i < numbers.size() to stay within bounds.
  // 2. Return a better signal value for empty input (-∞ or exception).
  // 3. Use > for strict maximum.
  static int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) return INT_MIN; // or throw std::runtime_error("Empty list");

    int maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {
      if (numbers[i] > maxVal) {
        maxVal = numbers[i];
      }
    }
    return maxVal;
  }
};
