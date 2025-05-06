// test_practice03.cpp

#include "gtest/gtest.h"

#include "practice03.cpp" 

// --------- Tests for sumRange ---------

TEST(MathUtilsTest, SumRange_ValidRange) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 10);  // Expected: 1+2+3+4 = 10
}


TEST(MathUtilsTest, SumRange_ZeroRange) {
    EXPECT_EQ(MathUtils::sumRange(5, 5), 0);
}


TEST(MathUtilsTest, SumRange_NegativeToPositive) {
    EXPECT_EQ(MathUtils::sumRange(-2, 3), -2 + -1 + 0 + 1 + 2); // Expected: 0
}


// --------- Tests for containsNegative ---------
TEST(MathUtilsTest, ContainsNegative_WithNegative) {
    std::vector<int> values = {3, -1, 5, 7};
    EXPECT_TRUE(MathUtils::containsNegative(values));
}


TEST(MathUtilsTest, ContainsNegative_NoNegative) {
    std::vector<int> values = {0, 2, 3};
    EXPECT_FALSE(MathUtils::containsNegative(values));
}


TEST(MathUtilsTest, ContainsNegative_AllNegative) {
    std::vector<int> values = {-5, -1, -3};
    EXPECT_TRUE(MathUtils::containsNegative(values));
}


TEST(MathUtilsTest, ContainsNegative_EmptyVector) {
    std::vector<int> values;
    EXPECT_FALSE(MathUtils::containsNegative(values));
}


// --------- Tests for findMax ---------

TEST(MathUtilsTest, FindMax_NormalCase) {
    std::vector<int> values = {1, 3, 2, 5, 4};
    EXPECT_EQ(MathUtils::findMax(values), 5);
}


TEST(MathUtilsTest, FindMax_NegativeValues) {
    std::vector<int> values = {-10, -20, -5};
    EXPECT_EQ(MathUtils::findMax(values), -5);
}


TEST(MathUtilsTest, FindMax_SingleElement) {
    std::vector<int> values = {42};
    EXPECT_EQ(MathUtils::findMax(values), 42);
}


TEST(MathUtilsTest, FindMax_EmptyVector) {
    std::vector<int> values;
    EXPECT_EQ(MathUtils::findMax(values), 0);  // As per current (buggy) implementation
}

