#include "ComplexArray.h"
#include <iostream>
#include <string>

ComplexArray::ComplexArray() : arr(nullptr), size(0) {}

ComplexArray::ComplexArray(int size) {
    this->size = size;
    this->arr = new Complex[this->size];
}

// Add this implementation to ComplexArray.cpp

ComplexArray::ComplexArray(const Complex* inputArray, int inputSize) {
    this->size = inputSize;
    if (this->size > 0) {
        this->arr = new Complex[this->size];
        // Perform a deep copy of each element
        for (int i = 0; i < this->size; ++i) {
            this->arr[i] = inputArray[i];
        }
    } else {
        this->arr = nullptr;
    }
}

ComplexArray::ComplexArray(const ComplexArray& other) {
    this->size = other.size;

    if (this->size > 0) {
        this->arr = new Complex[this->size];

        // Deep Copy
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = other.arr[i];
        }
    } else {
        this->arr = nullptr;
    }
}

ComplexArray::~ComplexArray() {
    // Free Memory
    delete[] this->arr;
}

int ComplexArray::getSize() const {
    return this->size;
}

ComplexArray& ComplexArray::operator=(const ComplexArray& other) {
    if (this == &other) return *this;

    // Free Old Memory;
    delete[] this->arr;

    this->size = other.size;

    if (this->size > 0) {
        this->arr = new Complex[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = other.arr[i];
        }
    } else {
        this->arr = nullptr;
    }
    return *this;
}

 Complex& ComplexArray::operator[](int index){
    if (index < 0) {
        index = this->size + index;
    }

    return this->arr[index];
}

bool ComplexArray::operator==(const ComplexArray& other) const {
    if (this->size != other.size) return false;

    for (int i = 0; i < this->size; i++) {
        if (this->arr[i] != other.arr[i]) {
            return false;
        }
    }

    return true;
}

bool ComplexArray::operator!=(const ComplexArray& other) const {
    return !(*this == other);
}

ComplexArray& ComplexArray::operator+=(const ComplexArray& other) {
    if (other.size == 0) return *this;

    int newSize = this->size + other.size;
    Complex* newArr = new Complex[newSize];

    // Copy the elements from the original array
    for (int i = 0; i < this->size; i++) {
        newArr[i] = this->arr[i];
    }

    // Copy the elements from the other array
    for (int i = 0; i < other.size; i++) {
        newArr[this->size + i] = other.arr[i];
    }

    // Free old memory
    delete[] this->arr;
    this->arr = newArr;
    this->size = newSize;

    return *this;
}

ComplexArray& ComplexArray::operator+=(const Complex& other) {
    int newSize = this->size + 1;
    // Correct way to allocate an ARRAY of Complex objects
    Complex* newArr = new Complex[newSize]; 
    
    // Copy the old elements
    for (int i = 0; i < this->size; i++) {
        newArr[i] = this->arr[i];
    }

    // Add the new element at the end
    newArr[this->size] = other;

    // Free the old memory and update the object
    delete[] this->arr;
    this->arr = newArr;
    this->size = newSize;

    return *this;
}



ComplexArray ComplexArray::operator+(const ComplexArray& other) const { 
    ComplexArray result = *this;
    result += other;
    return result;
}

Complex ComplexArray::operator!() const{
    Complex sum(0,0);
    for (int i = 0; i < this->size; ++i) {
        sum += this->arr[i];
    }

    return sum;
}

std::string ComplexArray::toString() const {
    if (this->size == 0) {
        return "";
    }

    std::string result = "";

    for (int i = 0; i < this->size; i++) {
        result += this->arr[i].toString();

        if (i < this->size - 1) {
            result += " ";
        }
    }

    return result;
}
std::ostream& operator<<(std::ostream& os, const ComplexArray& ca) {
    // Reuse the toString() method for a clean implementation.
    os << ca.toString();
    
    // Return the stream to allow for chaining (e.g., cout << arr1 << arr2;).
    return os;
}

std::istream& operator>>(std::istream& is, ComplexArray& ca) {
    int newSize = 0;
    std::cout << "Enter the number of complex numbers for the array: ";
    is >> newSize;

    // 1. Allocate a new temporary array to hold the user's input.
    Complex* newArr = new Complex[newSize];
    
    // 2. Loop and read each new Complex number from the user.
    for (int i = 0; i < newSize; ++i) {
        std::cout << "Enter complex number " << i + 1 << " (real imag): ";
        is >> newArr[i]; // This reuses the operator>> from your Complex class.
    }

    // 3. Free the array's old memory to prevent a memory leak.
    delete[] ca.arr;
    
    // 4. Update the array's members to point to the new data.
    ca.arr = newArr;
    ca.size = newSize;

    // 5. Return the stream to allow for chaining (e.g., cin >> arr1 >> arr2;).
    return is;
}

