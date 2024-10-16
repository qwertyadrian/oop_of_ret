/*
Напишите функцию `pow(double a, int b)`, которая возвращает значение `a` в степени `b`
*/

#include <iostream>

double pow(double a, int b);

int main() {
    double a = 4.24;
    int b = -2;

    printf("%.2f ^ %d = %.5f\n", a, b, pow(a, b));
    printf("%.2f ^ %d = %.5f\n", a, 0, pow(a, 0));
    printf("%.2f ^ %d = %.5f\n", a, -b, pow(a, -b));

    return 0;
}

double pow(double a, int b){
    double result = 1;
    if (b >= 0) {
        for (int i = 0; i < b; i++) {
            result *= a;
        }
    } else {
        result *= pow(1/a, -b);
    }
    return result;
}
