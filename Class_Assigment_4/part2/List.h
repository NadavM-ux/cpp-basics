#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

// Forward declaration of the class template
template<typename T>
class List;

// Forward declaration of the non-member operator<< function template
template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list);


template <typename T>
class List {
private:
    T* data;
    int size;

public:
    // Constructors and Destructor
    List();
    List(const List<T>& other);
    ~List();

    // Methods
    List<T>& clear();
    int count(const T& value) const;
    List<T>& append(const T& value);
    List<T>& extend(const List<T>& other);
    int index(const T& value) const;
    List<T>& remove(const int index);
    int length() const;

    // Operator Overloading
    List<T>& operator=(const List& other);
    List<T> operator+(const List<T>& other) const;
    List<T>& operator+=(const List& other);
    const T& operator[](int index) const;
    T& operator[](int index);
    List<T> operator[](const std::string& slice_str) const;
};


template <typename T>
List<T>::List() : data(nullptr), size(0) {}

template<typename T>
List<T>::List(const List<T>& other) : data(nullptr), size(0) {
    if (other.size > 0) {
        data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < this->size; i++) {
            data[i] = other.data[i];
        }
    }
}

template<typename T>
List<T>::~List() {
    delete[] data;
}

template<typename T>
List<T>& List<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    return *this;
}

template<typename T>
int List<T>::count(const T& value) const {
    int counter = 0;
    for (int i = 0; i < this->size; i++) {
        if (this->data[i] == value) {
            counter++;
        }
    }

    return counter;
}

template<typename T>
List<T>& List<T>::append(const T& value) {
    T* newData = new T[this->size + 1];

    for (int i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }

    newData[this->size] = value;
    delete[] this->data;

    this->data = newData;
    this->size++;
    return *this;
}

template<typename T>
List<T>& List<T>::extend(const List<T>& other) {
    int newSize = this->size + other.size;
    T* newList = new T[newSize];

    for (int i = 0; i < this->size; i++) {
        newList[i] = this->data[i];
    }

    for (int i = 0; i < other.size; i++) {
        newList[i + this->size] = other.data[i];
    }

    delete[] this->data;
    this->size = newSize;
    this->data = newList;
    return *this;
}

template<typename T>
int List<T>::index(const T& value) const {
    for (int i = 0; i < this->size; i++) {
        if (this->data[i] == value) return i;
    } 

    throw std::runtime_error("Value was not found in the list.");
}

template<typename T>
List<T>& List<T>::remove(const int index) {
    // Convert a negative index into a positive one
    // size = 5 , index = -1 >> 5 + (-1) = 4
    int actual_index = index;
    if (index < 0) {
        actual_index = this->size + index;
    }
    // Check if the index is out of bounds.
    
    if (actual_index < 0 || actual_index >= this->size) {
        throw std::out_of_range("Index Out Of Range");
    }

    // Create the new array with 1 less element.
    int newSize = this->size - 1;
    T* newData = new T[newSize];

    // Copy all the elements without the selected one
    int new_data_index = 0;
    for (int i = 0; i < this->size; i++) {
        if (i != actual_index) {
            newData[new_data_index] = this->data[i];
            new_data_index++;
        }
    }

    // Clean up old data
    delete[] this->data;
    this->data = newData;
    this->size = newSize;
    return *this;
}

template<typename T>
int List<T>::length() const {
    return this->size;
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {
    // Check for self-assigment.
    if (this == &other) return *this;

    // Delete old data in the current object.
    delete[] this->data;

    // Copy the size and allocate new memory
    this->size = other.size;
    if (other.size > 0) {
        this->data = new T[this->size];

        // Copy the elements from the other list to current one
        for (int i = 0; i < this->size; i++) {
            this->data[i] = other.data[i];
        }
    } else {
        this->data = nullptr;
    }   
    return *this;
}

template<typename T>
List<T> List<T>::operator+(const List<T>& other) const {
    List<T> newList = *this;

    // Use the extend method to add all the new elements.
    newList.extend(other);

    return newList;
}

template<typename T>
List<T>& List<T>::operator+=(const List& other) {
    this->extend(other);
    return *this;
}

template<typename T>
const T& List<T>::operator[](int index) const {
    int actual_index = index;
    if (index < 0) {
        actual_index = this->size + index;
    }
    // Check if the index is out of bounds.
    
    if (actual_index < 0 || actual_index >= this->size) {
        throw std::out_of_range("Index Out Of Rage");
    }

    return this->data[actual_index];
}

template<typename T>
T& List<T>::operator[](int index) {
    int actual_index = index < 0 ? this->size + index : index;
    if (actual_index < 0 || actual_index >= this->size) {
        throw std::out_of_range("Index Out Of Range");
    }
    return this->data[actual_index];
}

template<typename T>
List<T> List<T>::operator[](const std::string& slice_str) const {
    // 1. Find the colon to parse the string
    size_t colon_pos = slice_str.find(':');
    
    // Extract the substrings
    std::string start_substr = slice_str.substr(0, colon_pos);
    std::string end_substr = (colon_pos != std::string::npos) ? slice_str.substr(colon_pos + 1) : "";

    // 2. Set default start and end values
    int start_index = 0;
    int end_index = this->size;

    // 3. Convert substrings to integers if they are not empty
    if (!start_substr.empty()) {
        start_index = std::stoi(start_substr);
    }
    if (!end_substr.empty()) {
        end_index = std::stoi(end_substr);
    }

    // 4. Handle negative indexes
    if (start_index < 0) {
        start_index = this->size + start_index;
    }
    if (end_index < 0) {
        end_index = this->size + end_index;
    }

    // 5. Clamp indexes to be within the valid range [0, size]
    // -- REPLACED std::min and std::max WITH if STATEMENTS --
    int final_start = start_index;
    if (final_start < 0) {
        final_start = 0;
    }
    if (final_start > this->size) {
        final_start = this->size;
    }

    int final_end = end_index;
    if (final_end < 0) {
        final_end = 0;
    }
    if (final_end > this->size) {
        final_end = this->size;
    }
    
    // 6. Create the new list and append the sliced elements
    List<T> result;
    if (final_start < final_end) {
        for (int i = final_start; i < final_end; ++i) {
            result.append(this->data[i]);
        }
    }

    // 7. Return the newly created list
    return result;
}

// Add this entire function to the bottom of List.h

template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    os << "[";
    for (int i = 0; i < list.length(); i++) {
        os << list[i];
        if (i < list.length() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}