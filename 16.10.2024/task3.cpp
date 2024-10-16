/*
Напишите функцию для подсчета факториала
*/

#include <iostream>

int factorial(int n);

int main() {
    int a = 9;
    printf("%d! = %d", a, factorial(a));
    return 0;
}

int factorial(int n){
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
