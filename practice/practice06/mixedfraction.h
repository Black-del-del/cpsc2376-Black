#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "fraction.h"

class MixedFraction : public Fraction {
public:
    MixedFraction(int numerator, int denominator);
    MixedFraction(const Fraction& fraction);
    
    int getWhole() const;
    Fraction getFractionPart() const;

    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction);

private:
    int whole;
    Fraction fractionPart;
    void convertToMixed();// Other member functions...
};

#endif // MIXEDFRACTION_H