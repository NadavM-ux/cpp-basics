#include <iostream>

char* buildString(int size);
void printArray(char** arr, int size);
char** SortStringArray(char** arr, int size);

int main() {
    char** stringArray = new char* [5];
    for (int i = 0; i < 5; i++) {
        stringArray[i] = buildString(20);
    }
    std::cout << "Before Sort: " << std::endl;


}

// ** 
//  
// [nadav] [ori] [ofir] [...] [...]
//  *^.      *^.  *^.    *^.   *^. 

// char** SortStringArray(char** arr, int size) {
//     int temp;
//     int min = 21;

// 	for (int i = 0; i < size; i++) {
//         for (int j = i+1; j < size; j++) {
//             arr[i] < min;
//         }
//     }
// 	return arr;
// }


void printArray(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

char* buildString(int size) {
    char* str = new char[size];

    if (!str) {
        std::cout << "Error: Memory allocation failed!" << std::endl;
        return nullptr;
    }

    std::cin >> str;
    return str;
}