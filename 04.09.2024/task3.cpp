#include <iostream>
#include <time.h>
using namespace std;

/* Task3
 * Создать одномерный целочисленный массив N элементов
 * Проинициализировать случайными значениями, вывести на экран
 * Задать пороговое значение на клавиатуре, обнулить все элементы ниже порога
 * Вывести массив на экран
 */

const int SIZE = 12;

int main() {

    srand(time(nullptr));
    int arr[SIZE];
    int threshold;

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    printf("Enter a threshold value: ");
    scanf("%d", &threshold);

    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] < threshold)
            arr[i] = 0;
    }

    for (size_t i = 0; i < SIZE; i++) {
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    return 0;
}