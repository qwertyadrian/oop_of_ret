#include <iostream>
#include <time.h>
using namespace std;

/* Task8
 * Создать двумерный целочисленный массив NxN элементов
 * Проинициализировать случайными значениями, вывести на экран в виде матрицы
 * Определить номер строки, содержащий наибольшую последовательность из нулей
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

    int max_zeros = 0;
    int max_zeros_index = 0;
    int zeros = 0;

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 0) {
                zeros++;
            }
        }

        if (zeros > max_zeros) {
            max_zeros = zeros;
            max_zeros_index = i;
        }

        zeros = 0;
    }

    printf("Row %d has the most zeros: %d\n", max_zeros_index, max_zeros);

    return 0;
}