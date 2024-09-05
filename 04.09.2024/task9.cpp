#include <iostream>
#include <time.h>
using namespace std;

/* Task8
 * Создать двумерный целочисленный массив NxN элементов
 * Проинициализировать случайными значениями, вывести на экран в виде матрицы
 * Определить, является ли матрица симметричной
 * Вывести на экран
 */

const int SIZE = 6;

int main() {

    srand(time(nullptr));
    int matrix[SIZE][SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    bool symmetric = true;

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            if (matrix[i][j] != matrix[j][i]) symmetric = false;
        }
    }

    if (symmetric) {
        printf("Matrix is symmetric");
    } else {
        printf("Matrix is not symmetric");
    }

    return 0;
}