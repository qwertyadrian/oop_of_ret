#include <iostream>
#include <time.h>
using namespace std;

/* Task5
 * Создать одномерный целочисленный массив N элементов
 * Проинициализировать случайными значениями, вывести на экран
 * Написать сортировку для массива, отсортировать
 * Вывести массив на экран
 */

const int SIZE = 12;

int main() {

    srand(time(nullptr));
    int arr[SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n");

    for (size_t i = 0; i < SIZE; i++) {
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    return 0;
}