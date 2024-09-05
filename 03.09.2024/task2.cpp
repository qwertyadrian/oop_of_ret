#include <iostream>
#include <string>

/*
    Task1. Конвертер величин
    Программа запрашивает у пользователя число массы
    Затем в какой размерности (г, кг, ц, т)
    Затем в какую размерность перевести (г, кг, ц, т)
    Выводит результат конвертации
*/

int main() {

    std::string input;
    float mass;
    int inputDim, outputDim;

    float dimensions[4] = {1000, 50, 20, 1};

    std::cout << "Enter mass: ";
    std::getline(std::cin, input);
    mass = std::stof(input);

    std::cout << "Enter input dimension: \n1: g\n2: kg\n3: c\n4: t\n";
    std::getline(std::cin, input);
    inputDim = std::stoi(input);

    std::cout << "Enter output dimension: \n1: g\n2: kg\n3: c\n4: t\n";
    std::getline(std::cin, input);
    outputDim = std::stoi(input);

    if (inputDim > outputDim) {
        for (int i = inputDim - 1; i >= outputDim; i--) {
            mass *= dimensions[i-1];
        }
    } else {
        for (int i = inputDim; i < outputDim; i++) {
            mass /= dimensions[i-1];
        }
    }

    std::cout << "Result: " << mass << std::endl;

    return 0;
}