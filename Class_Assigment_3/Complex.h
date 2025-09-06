#pragma once
#include <string>

class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex();
        Complex(double realNumber);
        Complex(double realNumber, double imaginaryNumber);

        ~Complex();

        // Getters Setters
        double getReal() const;
        double getImaginary() const;

        void setReal(double real);
        void setImaginary(double imaginary);

        std::string toString() const;

        Complex& operator=(const Complex& other);
        Complex& operator+=(const Complex& other);
        Complex operator+(const Complex& other) const;
        operator double() const;

        // Comparsion
        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;

        // Increment Operator
        Complex& operator++();       // Prefix ++
        Complex operator++(int);    // Postfix ++
        double operator!() const;

        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        friend std::istream& operator>>(std::istream& is, Complex& c);
};