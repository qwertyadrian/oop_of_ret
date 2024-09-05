#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

/* Task6
 * Создать одномерный целочисленный массив N элементов
 * Проинициализировать случайными значениями, вывести на экран
 * Посчитать мат. ожидание и стандартное отклонение элементов
 * Вывести на экран
 */

const int SIZE = 10000;

int main() {

    srand(time(nullptr));
    int arr[SIZE];
    float m, o;

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 11;
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    m = 0;
    for (size_t i = 0; i < SIZE; i++) {
        m += arr[i];
    }
    m /= SIZE;

    for (size_t i = 0; i < SIZE; i++) {
        o += (arr[i] - m) * (arr[i] - m);
    }

    o /= SIZE;
    o = sqrt(o);

    printf("\n");
    printf("Mat. expec. = %.2f\n", m);
    printf("Stand. dev. = %.2f\n", o);

    return 0;
}