#include <iostream>
#include <time.h>
using namespace std;

/* Task7
 * Пользователь вводит N элементов массива с клавиатуры
 * Программа оценивает по следующим критериям:
 * - Последовательность знакочередующаяся
 * - Последовательность содержит одинаковые элементы
 * - Последовательность неубывающая
 * Вывести результат оценки на экран
 */

const int SIZE = 6;

int main() {

    srand(time(nullptr));
    int arr[SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        printf("Arr[%lu] = ", i);
        scanf("%d", &arr[i]);
    }

    bool is_alternating = true;
    bool has_same = false;
    bool is_non_decreasing = true;

    for (size_t i = 0; i < SIZE-1; i++) {
        if (arr[i] >= arr[i+1]) is_non_decreasing = false;
        if (arr[i] * arr[i+1] > 0) is_alternating = false;
    }

    for (size_t i = 0; i < SIZE-1; i++) {
        for (size_t j = i+1; j < SIZE; j++) {
            if (i != j && arr[i] == arr[j]) has_same = true;
        }
    }

    if (is_alternating) printf("The sequence is alternating\n");
    if (has_same) printf("The sequence has same elements\n");
    if (is_non_decreasing) printf("The sequence is non-decreasing\n");

    return 0;
}