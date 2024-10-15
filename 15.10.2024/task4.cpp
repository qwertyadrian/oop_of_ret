/*
    Реализуйте программу, которая создаёт динамический массив размером 3x3 элемента
    Заполните матрицу с клавиатуры и выведите на экран.
 */
#include <iostream>

constexpr int rows = 3;
constexpr int cols = 3;

int main() {
    // int (*arr)[3] = new int[3][3];
    // auto arr = new int[3][3];
    int** arr = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("Arr[%lu][%lu] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("Arr[%lu][%lu] = %d\n", i, j, arr[i][j]);
        }
    }

    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}