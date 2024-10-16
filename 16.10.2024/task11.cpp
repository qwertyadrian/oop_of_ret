/*
Создайте структуру `Point3D` для представления точки в трехмерном пространстве.
Напишите функцию, которая принимает две точки по ссылке и возвращает расстояние между ними.
*/
#include <iostream>
#include <cmath>

struct Point3D {
    double x;
    double y;
    double z;
};

double distance(Point3D* p1, Point3D* p2){
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
}

int main() {
    Point3D a{1, 2, 3}, b{4, 5, 6};

    printf("Distance between a and b: %.2f", distance(&a, &b));

    return 0;
}
