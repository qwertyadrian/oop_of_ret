#include <iostream>
#include <string>

/*
    Task1. Простейший калькулятор
*/

int main() {

    std::string input;
    float num1, num2;
    int opType;

    std::cout << "Enter num1: ";
    std::getline(std::cin, input);
    num1 = std::stof(input);

    std::cout << "Enter num2: ";
    std::getline(std::cin, input);
    num2 = std::stof(input);

    std::cout << "Enter operator:\n1: +\n2: -\n3: *\n4: /\n";
    std::getline(std::cin, input);
    opType = std::stoi(input);

    switch(opType) {
        case 1:
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case 4:
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            break;
        default:
            break;
    }

    return 0;
}