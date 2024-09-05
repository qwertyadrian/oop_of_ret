#include <iostream>
#include <time.h>
using namespace std;

/* Task4
 * Создать одномерный целочисленный массив N элементов
 * Проинициализировать случайными значениями, вывести на экран
 * Перевернуть элементы внутри массива (именно массива, а не только на выводе)
 * Вывести массив на экран
 */

const int SIZE = 12;

int main() {

    srand(time(nullptr));
    int arr[SIZE];
    int temp;

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    for (size_t i = 0; i < SIZE / 2; i++) {
        temp = arr[i];
        arr[i] = arr[SIZE - 1 - i];
        arr[SIZE - 1 - i] = temp;
    }

    printf("\n");

    for (size_t i = 0; i < SIZE; i++) {
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    return 0;
}