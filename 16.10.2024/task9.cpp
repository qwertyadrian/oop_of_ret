/*
Создайте структуру `Rectangle` с полями длины и ширины. Напишите функцию, позволяющую задать новые значения
длины и ширины у объекта такой структуры.
*/
#include <iostream>

struct Rectangle {
    double len;
    double wid;
};

void change_size(Rectangle* rect, double new_len, double new_wid){
    rect->len = new_len;
    rect->wid = new_wid;
}

int main() {
    Rectangle rect{42.2, 12.8};

    printf("Rectangle: l=%.2f, w=%.2f\n", rect.len, rect.wid);
    change_size(&rect, 8.2, 83.1);
    printf("Rectangle after change_size() call: l=%.2f, w=%.2f", rect.len, rect.wid);

    return 0;
}

