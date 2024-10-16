/*
    Напишите следующие функции, возвращающие результат операции для двух чисел:
    Сумма
    Разность
    Произведение
    Отношение
*/
#include <iostream>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
double divide(double a, double b);

int main() {
    int a = 8;
    int b = 32;

    printf("%d + %d = %d\n", a, b, sum(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d * %d = %d\n", a, b, mul(a, b));
    printf("%d / %d = %.2f\n", a, b, divide(a, b));

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

float divide(float a, float b){
    return a / b;
}
