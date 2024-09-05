#include <iostream>
#include <time.h>
using namespace std;

/* Task2
 * Создать одномерный целочисленный массив N элементов
 * Проинициализировать случайными значениями, вывести на экран
 * Найти индексы всех локальных максимумов, вывести на экран
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
        if (i == 0) {
            if (arr[i] > arr[i + 1]) {
                printf("Local max is %d on index %lu\n", arr[i], i);
            }
        } else if (i == SIZE - 1) {
            if (arr[i] > arr[i - 1]) {
                printf("Local max is %d on index %lu\n", arr[i], i);
            }
        } else {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
                printf("Local max is %d on index %lu\n", arr[i], i);
            }
        }
    }

    return 0;
}