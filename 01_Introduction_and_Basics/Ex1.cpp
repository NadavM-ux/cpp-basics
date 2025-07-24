#include <iostream>

using namespace std;

int* create_array(int size);
int* merge_arrays(int* arr1, int* arr2, int size_arr1, int size_arr2);
void print_array(int* arr, int size);

int main() {
    int number;
    
    cout << "Choose the size of the array: ";
    cin >> number;

    int* my_array = create_array(number);
    print_array(my_array, number);

	return 0;
}

int* merge_arrays(int* arr1, int* arr2, int size1, int size2, int* newSize) {
    int count = 0;
    *newSize  = size1 + size2;

    for (int i = 0, j = 0; i < size1 && j <size2;) {
        if (arr1[i] == arr2[j]) {
            (*newSize)--;
        }
        i++;
        j++;
    }
    else if (arr1[i] < arr2[j]) i++;


}

void print_array(int* arr, int size) {
    for (int i = 0; i < size-1; i++) 
        cout << arr[i] << ", ";
    cout << arr[size - 1] << endl;
}

int* create_array(int size) {
    int* my_arr = new int[size];

    if (!my_arr) {
        cout << "Error: Memory allocation failed!" << endl;
        return nullptr;
    }


    cout << "Please enter " << size << " numbers in acending order" << endl;
    for (int i = 0; i < size; i++) {
        cin >> my_arr[i];
    }

    return my_arr;
}
    

