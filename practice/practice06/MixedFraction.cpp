#include "MixedFraction.h"
#include <iostream>
#include <cmath>

// Constructor to initialize a mixed fraction
MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d), whole(whole) {}

// Constructor to convert a fraction to mixed form
MixedFraction::MixedFraction(const Fraction& fraction) {
    int totalNumerator = fraction.getNumerator();
    int denominator = fraction.getDenominator();
    whole = totalNumerator / denominator;
    int remainder = totalNumerator % denominator;
    setNumerator(remainder); // Set the remaining numerator
    setDenominator(denominator); // Set denominator
}

// Overload stream operator for mixed fraction format
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction) {
    if (mixedFraction.whole != 0) {
        os << mixedFraction.whole << " ";
    }
    os << mixedFraction.getNumerator() << "/" << mixedFraction.getDenominator();
    return os;
}
