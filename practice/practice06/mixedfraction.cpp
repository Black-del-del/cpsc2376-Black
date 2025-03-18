#include "mixedfraction.h"
#include "fraction.h"
#include <iostream>

MixedFraction::MixedFraction(int numerator, int denominator) : Fraction(numerator, denominator) {convertToMixed();}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) { convertToMixed();
    // Additional initialization if needed
}
// Overloading << operator to print the MixedFraction in mixed fraction format

int MixedFraction::getWhole() const {
    return whole;
}

Fraction MixedFraction::getFractionPart() const {
    return fractionPart;
}

void MixedFraction::convertToMixed() {
    whole = getNumerator() / getDenominator();
    int newNumerator = getNumerator() % getDenominator();
    fractionPart = Fraction(newNumerator, getDenominator());
}
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction) {
    if (mixedFraction.whole != 0) {
        os << mixedFraction.whole;
        if (mixedFraction.fractionPart.getNumerator() != 0) {
            os << " " << mixedFraction.fractionPart;
        }
    } else {
        os << mixedFraction.fractionPart;
    }
    return os;
}
