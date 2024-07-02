#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
public:
    double real, imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    bool operator<(const Complex& other) const {
        return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * other.real + other.imag * other.imag);
    }
};

#endif // COMPLEX_H
