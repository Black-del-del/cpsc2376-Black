#include "Fraction.h"
#include <iostream>
#include <stdexcept> // For invalid_argument exception

// Constructor: Default to 0/1
Fraction::Fraction() : num(0), den(1) {}

// Constructor: Accepts numerator and denominator
Fraction::Fraction(int n, int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero.");
    num = n;
    den = d;
    simplify();
}

// Getters
int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

// Setters
void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero.");
    den = d;
    simplify();
}

// Simplify the fraction using Euclidean algorithm
void Fraction::simplify() {
    int a = num;
    int b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;

    // Ensure the denominator is positive
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

// Arithmetic operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int num = lhs.num * rhs.den + rhs.num * lhs.den;
    int den = lhs.den * rhs.den;
    return Fraction(num, den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int num = lhs.num * rhs.den - rhs.num * lhs.den;
    int den = lhs.den * rhs.den;
    return Fraction(num, den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int num = lhs.num * rhs.num;
    int den = lhs.den * rhs.den;
    return Fraction(num, den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("Cannot divide by zero.");
    int num = lhs.num * rhs.den;
    int den = lhs.den * rhs.num;
    return Fraction(num, den);
}

// Stream overload for printing
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.num << "/" << fraction.den;
    return os;
}
