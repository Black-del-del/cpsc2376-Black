#include "fraction.h"
#include <algorithm>  // For std::min and std::max

Fraction::Fraction(int numerator, int denominator) : num(numerator), den(denominator) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int newNum = num * other.den + other.num * den;
    int newDen = den * other.den;
    return Fraction(newNum, newDen);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int newNum = num * other.den - other.num * den;
    int newDen = den * other.den;
    return Fraction(newNum, newDen);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int newNum = num * other.num;
    int newDen = den * other.den;
    return Fraction(newNum, newDen);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.num == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    int newNum = num * other.den;
    int newDen = den * other.num;
    return Fraction(newNum, newDen);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.num << '/' << fraction.den;
    return os;
}

void Fraction::simplify() {
    int gcd = std::min(num, den);
    while (gcd > 1) {
        if (num % gcd == 0 && den % gcd == 0) {
            break;
        }
        --gcd;
    }
    if (gcd == 0) {
        gcd = (num == 0) ? den : num;
        while (den != 0) {
            int temp = den;
            den = num % den;
            num = temp;
        }
        gcd = num;
    }
    num /= gcd;
    den /= gcd;
}