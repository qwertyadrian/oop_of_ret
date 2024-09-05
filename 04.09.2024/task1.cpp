#include <iostream>
#include <time.h>
using namespace std;

/* Task1
 * Создать одномерный целочисленный массив N элементов
 * Проинициализировать случайными значениями, вывести на экран
 * Найти максимальный элемент и его индекс в массиве, вывести на экран
 */

const int SIZE = 12;

int main() {

    srand(time(nullptr));
    int arr[SIZE];
    int maxValue;
    size_t maxIndex(0);

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    maxValue = arr[0];

    for (size_t i = 0; i < SIZE; i++) {
        if (maxValue < arr[i]) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    printf("Max value is %d on index %lu", maxValue, maxIndex);

    return 0;
}