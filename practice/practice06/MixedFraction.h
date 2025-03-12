#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int whole; // Whole number part

public:
    // Constructors
    MixedFraction(int whole, int n, int d);
    MixedFraction(const Fraction& fraction); // Converts a fraction to mixed form

    // Stream overload to display mixed fraction
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction);
};

#endif // MIXEDFRACTION_H
