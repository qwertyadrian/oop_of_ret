/*
    Напишите программу, которая динамически выделяет память для массива из
    5-и целых чисел, заполните массив с клавиатуры, а затем выведите его элементы
    После завершения работы освободить выделенную память
 */
#include <iostream>

int main() {
    int* arr = new int[5];

    for (size_t i = 0; i < 5; i++) {
        printf("Arr[%lu] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n");

    for (size_t i = 0; i < 5; i++) {
        printf("Arr[%lu] = %d\n", i, arr[i]);
    }

    delete[] arr;
    return 0;
}