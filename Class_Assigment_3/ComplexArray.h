#pragma once
#include "Complex.h"
#include "iostream"
#include "string"

class ComplexArray {
    private:
        Complex* arr;
        int size;
    public:
        ComplexArray();
        ComplexArray(const Complex* arr, int size);
        ComplexArray(int size);
        ComplexArray(const ComplexArray& other);
        ~ComplexArray();
        
        int getSize() const;
        
        ComplexArray& operator=(const ComplexArray& other);

        Complex& operator[](int index);
        bool operator==(const ComplexArray& other) const;
        bool operator!=(const ComplexArray& other) const;

        ComplexArray operator+(const ComplexArray& other) const;
        ComplexArray& operator+=(const ComplexArray& other);
        ComplexArray& operator+=(const Complex& other);

        Complex operator!() const;

        std::string toString() const;

        // --- Friend Functions for Stream I/O ---
        friend std::ostream& operator<<(std::ostream& os, const ComplexArray& ca);
        friend std::istream& operator>>(std::istream& is, ComplexArray& ca);
};