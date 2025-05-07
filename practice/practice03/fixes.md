THe problems with the code included

sumRange(int start, int end)

Bug: The loop ran from start to end - 1 (i < end), excluding the end value.

Fix: Changed the condition to i <= end to include the full range.

containsNegative(const std::vector<int>& numbers)

Bug 1: The loop used i <= numbers.size(), which causes out-of-bounds access on the last iteration.

Fix: Changed to i < numbers.size().

Bug 2: The condition was if (numbers[i] > 0), which checks for positives instead of negatives.

Fix: Corrected to numbers[i] < 0.

findMax(const std::vector<int>& numbers)

Bug 1: The loop condition was i <= numbers.size(), causing out-of-bounds access.

Fix: Changed to i < numbers.size().

Bug 2: The comparison used >=, which can cause unnecessary overwrites when values are equal.

Fix: Changed to > for proper max logic.
