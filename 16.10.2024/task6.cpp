/*
Напишите программу, которая запрашивает у пользователя границы диапазона.
А затем выводит все простые числа в диапазоне.
*/

#include <iostream>

void prime_numbers(int low, int high);

int main() {
    int low, high;

    printf("Enter low and high: ");
    scanf("%d %d", &low, &high);

    prime_numbers(low, high);

    return 0;
}

void prime_numbers(int low, int high){
    for (int i = low; i <= high; i++){
        bool is_prime = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            printf("%d ", i);
        }
    }
}
