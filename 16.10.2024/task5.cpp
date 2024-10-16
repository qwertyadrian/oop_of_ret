/*
Напишите функцию `swap`, которая меняет местами значения двух целочисленных переменных.
*/
#include <iostream>

void swap(int* a, int* b);

int main() {
    int a(8), b(42);

    printf("Before swap() call: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap() call: a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}