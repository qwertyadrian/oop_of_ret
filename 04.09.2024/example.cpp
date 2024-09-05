#include <iostream>
#include <time.h>

const int ARR_SIZE = 10;

int main() {

    int arr[ARR_SIZE];
    int matrix[ARR_SIZE][ARR_SIZE];
    srand(time(nullptr));

    for (size_t i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 11;
    }

    for (size_t i = 0; i < ARR_SIZE; i++) {
        std::cout << "Arr[" << i << "] = " << arr[i] << std::endl;
    }

    for (size_t i = 0; i < ARR_SIZE; i++) {
        for (size_t j = 0; j < ARR_SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    for (size_t i = 0; i < ARR_SIZE; i++) {
        for (size_t j = 0; j < ARR_SIZE; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
