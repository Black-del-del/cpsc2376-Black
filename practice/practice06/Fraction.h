#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept> // For exceptions

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator

    void simplify(); // Helper function to simplify the fraction

public:
    // Constructors
    Fraction(); // Default constructor
    Fraction(int n, int d); // Parameterized constructor

    // Getter and setter functions
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d); // Throws exception if d == 0

    // Overloaded operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs); // Throws exception for division by zero

    // Stream overload
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
};

#endif // FRACTION_H
