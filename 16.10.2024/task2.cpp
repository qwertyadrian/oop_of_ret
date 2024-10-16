/*
Напишите функцию, которая принимает указатель на целое число
и увеличивает значение этого числа на 10
*/

#include <iostream>

void add10(int* a);

int main() {
    int a = 10;

    printf("a before add10() call: %d\n", a);
    add10(&a);
    printf("a after add10() call: %d\n", a);

    return 0;
}

void add10(int* a){
    *a += 10;
}
