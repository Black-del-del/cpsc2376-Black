#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>  // For std::invalid_argument

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1);
    int getNumerator() const;
    int getDenominator() const;

    // Overload operators
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

private:
    int num;
    int den;
    void simplify();
};

#endif // FRACTION_H
