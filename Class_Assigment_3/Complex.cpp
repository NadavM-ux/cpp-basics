#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() : real(0.0), imaginary(0.0) {} // 0 + 0i
Complex::Complex(double realNumber) : real(realNumber), imaginary(0.0) {}
Complex::Complex(double realNumber, double imaginaryNumber) : real(realNumber), imaginary(imaginaryNumber) {}

Complex::~Complex() {}

double Complex::getReal() const {
    return this->real;
}

double Complex::getImaginary() const {
    return this->imaginary;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

std::string Complex::toString() const {
    if (imaginary == 0.0) {
        return std::to_string(real);
    }

    if (real == 0.0) {
        return std::to_string(imaginary) + "i";
    }

    if (imaginary < 0) {
        return std::to_string(real) + " - " + std::to_string(-imaginary) + "i";
    }

    return std::to_string(real) + " + " + std::to_string(imaginary) + "i";
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        this->real = other.real;
        this->imaginary = other.imaginary;
    }

    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;

    return *this; // Return by refrence
}

Complex Complex::operator+(const Complex& other) const {
    Complex result = *this;

    result += other;

    return result;
}


bool Complex::operator==(const Complex& other) const {
    return (this->real == other.real) && (this->imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

 Complex::operator double() const {
    return this->real + this->imaginary;
}

Complex& Complex::operator++() {
    this->real++;
    return *this;
}

Complex Complex::operator++(int num) {
    Complex temp = *this;

    this->real += 1.0;

    return temp;
}

double Complex::operator!() const {
    return sqrt(abs(this->real * this->real) + abs(this->imaginary * this->imaginary));
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.toString();

    return os;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
    double real_part;
    double imag_part;
    char colon; // A char variable to consume the colon

    // Read a double, then a char, then another double
    is >> real_part >> colon >> imag_part;

    complex.setReal(real_part);
    complex.setImaginary(imag_part);

    return is;
}