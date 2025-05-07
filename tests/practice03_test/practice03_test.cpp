#include "MathUtils.h"
#include <gtest/gtest.h>
#include <vector>
#include "pch.h"

TEST(MathUtilsTest, SumRangeNormal) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15);
}

TEST(MathUtilsTest, SumRangeThrows) {
    EXPECT_THROW(MathUtils::sumRange(10, 5), std::invalid_argument);
}

TEST(MathUtilsTest, ContainsNegativeTrue) {
    std::vector<int> nums = { 1, -2, 3 };
    EXPECT_TRUE(MathUtils::containsNegative(nums));
}

TEST(MathUtilsTest, ContainsNegativeFalse) {
    std::vector<int> nums = { 1, 2, 3 };
    EXPECT_FALSE(MathUtils::containsNegative(nums));
}

TEST(MathUtilsTest, FindMaxNormal) {
    std::vector<int> nums = { 3, 9, 1, 7 };
    EXPECT_EQ(MathUtils::findMax(nums), 9);
}

TEST(MathUtilsTest, FindMaxThrows) {
    std::vector<int> nums;
    EXPECT_THROW(MathUtils::findMax(nums), std::invalid_argument);
}
