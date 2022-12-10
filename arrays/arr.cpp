#include <iostream>

const int ARR_LEN = 3;
#define ARR_LEN2 3

void printArray() {
    int arr[] = { 1, 2, 3 };
    for (int i = 0; i < ARR_LEN; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << (arr)[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    printArray();

    int arr2[] = { 123, 2, 3 };
    printArray(arr2, 3);

    char* arr3[] = { "111", "222", "333" };
    printArray(arr3, 3);

    return 0;
}