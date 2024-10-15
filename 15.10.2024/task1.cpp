/*
    Напишите программу, которая создаёт целое число, затем создаёт указатель на это число
    С помощью указателя поменяйте содержимое целого числа и выведите его на экран
*/
#include <iostream>

int main() {
    int a = 42;
    int* a_ptr = &a;

    printf("A value: %d\n", a);
    printf("A ptr value: %p\n", a_ptr);
    printf("A size: %lu bytes\n", sizeof(a));
    printf("A ptr size: %lu bytes\n\n", sizeof(a_ptr));

    *a_ptr = 24;
    printf("A value after change: %d\n", a);
    printf("A ptr value after change: %p\n", a_ptr);
}