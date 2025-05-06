#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "practice03.cpp" // Ideally include a header, not the .cpp

TEST_CASE("sumRange computes inclusive sum of range [start, end]") {
    REQUIRE(MathUtils::sumRange(1, 5) == 15);  // 1+2+3+4+5
    REQUIRE(MathUtils::sumRange(0, 0) == 0);   // empty range
    REQUIRE(MathUtils::sumRange(3, 4) == 3);   // single number
    REQUIRE(MathUtils::sumRange(-2, 3) == -2 + -1 + 0 + 1 + 2); // negative to positive
}

TEST_CASE("containsNegative returns true if any negative number is present") {
    REQUIRE(MathUtils::containsNegative({1, -2, 3}) == true);
    REQUIRE(MathUtils::containsNegative({0, 0, 0}) == false);
    REQUIRE(MathUtils::containsNegative({}) == false);
    REQUIRE(MathUtils::containsNegative({-1}) == true);
}

TEST_CASE("findMax returns the maximum value in the list") {
    REQUIRE(MathUtils::findMax({1, 5, 3, 7, 2}) == 7);
    REQUIRE(MathUtils::findMax({-5, -2, -9}) == -2);
    REQUIRE(MathUtils::findMax({10}) == 10);
    REQUIRE(MathUtils::findMax({}) == 0); // edge case: empty list
}
