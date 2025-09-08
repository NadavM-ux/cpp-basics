#pragma once
#include "List.h" // Required because doTwice uses the List class

/**
 * @brief Creates a new list where each element from the original list is duplicated.
 * @tparam T The type of elements in the list.
 * @param original_list The source list, which will not be modified.
 * @return A new List<T> with each element appearing twice.
 */
template<typename T>
List<T> doTwice(const List<T>& original_list) {
    // Create a new list
    List<T> newList;

    // Loop through each element of the original list
    for (int i = 0; i < original_list.length(); i++) {
        newList.append(original_list[i]);
        newList.append(original_list[i]);
    }

    return newList;
}

/**
 * @brief Finds the largest element in a C-style array.
 * @tparam T The type of elements in the array. Must support the > operator.
 * @param arr A pointer to the beginning of the array, which will not be modified.
 * @param size The number of elements in the array.
 * @return The largest element found in the array.
 */
template<typename T>
T maxT(const T* arr, int size) {
    T max_val = arr[0];
    // Start loop at 1 for a small optimization
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}