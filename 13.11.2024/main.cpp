#include "MyComplex.h"
#include "cat.h"
#include "fraction.h"
#include "int8.h"
/*
 * public - публичные поля/методы класса
 * protected -
 * private - приватные поля/методы доступны только изнутри класса
 */

/*
 * Задача 1.
 * Описать класс обыкновенной дроби (минус хранить в числителе).
 * В параметрах объявить делитель и знаменатель.
 * Перегрузить операторы сложения, вычитания, умножения, деления
 * и их сокращенные версии.
 * Перегрузить оператор инкремента и декремента (манипулировать с числителями) (как постфикс так и префикс).
 * Конструктор, конструктор копирования и деструктор.
 * Созданный приватный метод сокращения дроби -> дробь стремится быть нормальной ;(
 * Вызов происходит в любой доступный момент, когда дробь может вдруг оказаться не сокращенной.
 * Создать публичный метод наименьшего общего знаменателя.
 *
 * Задача 2.
 * Описать класс комплексных чисел.
 *
 * Задача 3.
 * Описать класс int8_signed и int8_unsigned из двух short — левой части int и правой части int.
 */


int main() {
    // std::string name = "Fedor";
    // Cat *fedor = new Cat(name, 3, 10);
    // Cat venya(*fedor);
    // Cat fedorII(venya);
    // Cat nullCat = fedorII;

    // fedor->feed(10);
    // fedor->setName(name);
    // venya.setName(name.append(" the First"));

    // printf("Fedor mass: %d\n", fedor.getMass());
    // printf("Venya mass: %d\n", venya.getMass());
    // printf("%s\n", fedor.getName().c_str());
    // printf("%s\n", venya.getName().c_str());
    // printf("%s\n", fedorII.getName().c_str());
    // delete fedor;

    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction x(12, 15);
    Fraction y(3, 7);

    Fraction c = a + b;
    c.print();

    Fraction d = a - b;
    d.print();

    Fraction e = a * b;
    e.print();

    Fraction f = a / b;
    f.print();

    Fraction g = a;
    g++;
    g.print();

    printf("LCM: %d\n", x.lcm(y));

    Complex c1(1, 2);
    Complex c2(3, 4);

    Complex c3 = c2 * 2;
    c3.print();

    Int8 int8Signed(-246*2);
    Int8 int8Signed2(-123);
    printf("\nValue: %d\n", int8Signed.getValue());
    printf("Left: %d\n", int8Signed.getLeft());
    printf("Right: %d\n\n", int8Signed.getRight());

    printf("Value2: %d\n", int8Signed2.getValue());
    printf("Left2: %d\n", int8Signed2.getLeft());
    printf("Right2: %d\n\n", int8Signed2.getRight());

    Int8 int8Signed3 = int8Signed + int8Signed2;
    printf("+: %d\n", int8Signed3.getValue());
    printf("Left: %d\n", int8Signed3.getLeft());
    printf("Right: %d\n\n", int8Signed3.getRight());

    Int8 int8Signed4 = int8Signed - int8Signed2;
    printf("-: %d\n", int8Signed4.getValue());
    printf("Left: %d\n", int8Signed4.getLeft());
    printf("Right: %d\n\n", int8Signed4.getRight());

    Int8 int8Signed5 = int8Signed * int8Signed2;
    printf("*: %d\n", int8Signed5.getValue());
    printf("Left: %d\n", int8Signed5.getLeft());
    printf("Right: %d\n\n", int8Signed5.getRight());

    Int8 int8Signed6 = int8Signed / int8Signed2;
    printf("/: %d\n", int8Signed6.getValue());
    printf("Left: %d\n", int8Signed6.getLeft());
    printf("Right: %d\n\n", int8Signed6.getRight());

    Int8 int8Signed7 = -int8Signed;
    printf("Value: %d\n", int8Signed7.getValue());
    printf("Left: %d\n", int8Signed7.getLeft());
    printf("Right: %d\n\n", int8Signed7.getRight());

    if (int8Signed == int8Signed2) {
        printf("int8Signed == int8Signed2\n");
    } else {
        printf("int8Signed != int8Signed2\n");
    }

    if (int8Signed < int8Signed2) {
        printf("int8Signed < int8Signed2\n");
    } else {
        printf("int8Signed >= int8Signed2\n");
    }

    if (int8Signed > int8Signed2) {
        printf("int8Signed > int8Signed2\n");
    } else {
        printf("int8Signed <= int8Signed2\n");
    }

    UInt8 int8Unsigned(1024*128);
    UInt8 int8Unsigned2(1024);

    printf("\nValue: %d\n", int8Unsigned.getValue());
    printf("Left: %d\n", int8Unsigned.getLeft());
    printf("Right: %d\n\n", int8Unsigned.getRight());

    printf("Value2: %d\n", int8Unsigned2.getValue());
    printf("Left2: %d\n", int8Unsigned2.getLeft());
    printf("Right2: %d\n\n", int8Unsigned2.getRight());

    UInt8 int8Unsigned3 = int8Unsigned + int8Unsigned2;
    printf("+: %d\n", int8Unsigned3.getValue());
    printf("Left: %d\n", int8Unsigned3.getLeft());
    printf("Right: %d\n\n", int8Unsigned3.getRight());

    UInt8 int8Unsigned4 = int8Unsigned - int8Unsigned2;
    printf("-: %d\n", int8Unsigned4.getValue());
    printf("Left: %d\n", int8Unsigned4.getLeft());
    printf("Right: %d\n\n", int8Unsigned4.getRight());

    UInt8 int8Unsigned5 = int8Unsigned * int8Unsigned2;
    printf("*: %d\n", int8Unsigned5.getValue());
    printf("Left: %d\n", int8Unsigned5.getLeft());
    printf("Right: %d\n\n", int8Unsigned5.getRight());

    UInt8 int8Unsigned6 = int8Unsigned / int8Unsigned2;
    printf("/: %d\n", int8Unsigned6.getValue());
    printf("Left: %d\n", int8Unsigned6.getLeft());
    printf("Right: %d\n\n", int8Unsigned6.getRight());

    return 0;
}
