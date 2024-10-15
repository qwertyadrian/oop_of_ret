/*
    Напишите программу, которая создаёт указатель на целое число, затем
    указатель на указатель. Используя указатель на указатель, измените число и выведите
    его снова.
 */
#include <iostream>

int main() {
    int a = 42;
    int* a_ptr = &a;
    int** a_ptr_ptr = &a_ptr;

    printf("Value: %d\n", **a_ptr_ptr);

    **a_ptr_ptr = 24;

    printf("Value after change: %d\n", **a_ptr_ptr);

    return 0;
}