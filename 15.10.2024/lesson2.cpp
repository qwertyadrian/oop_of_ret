/*
    Функции и структуры
    Объявление функции
    Объявление структуры
 */
#include <iostream>

struct Point2D {
    double x;
    double y;
};

struct Line2D {
    Point2D start_point;
    Point2D end_point;
};

int sum(int num1, int num2); // Сигнатура функции

int main() {
    Point2D my_point{10, 20};
    // Point2D line[2];

    printf("Point x: %f\n", my_point.x);
    printf("Point y: %f\n", my_point.y);

    my_point.x = 100;
    my_point.y = 200;

    printf("Point x: %f\n", my_point.x);
    printf("Point y: %f\n", my_point.y);

    Line2D my_line{{1, 1}, {5, 5}};
    printf("Line start: (%f, %f)\n", my_line.start_point.x, my_line.start_point.y);
    printf("Line end: (%f, %f)\n", my_line.end_point.x, my_line.end_point.y);

    printf("Sum function result: %d\n", sum(10, 20));

    return 0;
}

int sum(int num1, int num2) {
    return num1 + num2;
}