#include <iostream>

#include "MyVector.h"
#include "MyVectorPtr.h"
#include "MyList.h"

/*
 * Задание.
 * 1. Описать шаблонный класс MyVector, реализующий функционал вектора
 * из стандартной библиотеки C++ (переписать функции из пятого задания 29.10.2024).
 *
 * 2. Описать шаблонный класс MyList, реализующий функционал forwarded_list<> из
 * std (можно реализовать только функционал из пятого задания).
 *
 * 3. Переписать текст пятой программы используя описанные классы.
 */

/*
 * 1. Полиморфизм методов:
 * 1.1. Перегрузка (overload)
 * 1.2. Переопределение через наследование (override)
 * 1.3. Шаблоны
 *
 * 2. Полиморфизм данных
 * 2.1. Перегрузка (overload)
 * 2.2. Шаблоны
 */

/*
 * Перегрузка функций (класса)
 * Функции с одним и тем же названием, обладают разной сигнатурой
 * и выполняют разные действия (но концептуально одно и то же действие)
 */

// Пример «Полиморфизм данных» с overload
int sum(int a, int b) {
    printf("Int version\n");
    return a + b;
} // int sum(int, int)

double sum(double a, double b) {
    printf("Double version\n");
    return a + b;
} // double sum(double, double)

// Пример «Полиморфизм данных» + «Полиморфизм методов» с overload
std::string sum(char a, char b) {
     printf("Char version\n");
     return std::string(1, a) + b;
} // std::string sum(char, char)

// Шаблоны
template<typename T>
T sum(T a, T b) {
    printf("Template version\n");
    return a + b;
} // T sum(T, T)

/*
 * Концепт наследования (ленивого расширения)
 */

class BaseClass {
    protected:
        double _a;
        double _b;
    public:
        BaseClass(double a, double b) : _a(a), _b(b) {}
        double sum() {return _a + _b;}
};
/*
 * Модификаторы наследования:
 * public - public(B) -> public(D), protected(B) -> protected(D), private(B) -> private(D)
 * protected - public(B) -> protected(D), protected(B) -> protected(D), private(B) -> private(D)
 * private - public(B) -> private(D), protected(B) -> private(D), private(B) -> private(D)
 */
class Derived : public BaseClass {
    private:
        double _c;
    public:
        Derived(double a, double b) : BaseClass(a, b) {}
        void newFunc() {printf("Derived: %f", _a * _b);}
};

class Derived2 : public Derived {
    public:
        Derived2(double a, double b) : Derived(a, b) {}
        void superNewFunc() {printf("Derived2: %f", _a*_b + _b*_a);}
};



int main() {
    auto res = sum(1, 2);
    printf("Res: %d\n", res);

    auto res_str = sum('a', 'b');
    printf("Res: %s\n", res_str.c_str());

    size_t size = 1000;
    MyVector<int> vec(size);
    MyVectorPtr<int> vecPtr(size);
    MyList<int> list;

    for (int i = 0; i < size; i++) {
        vec.push_back(i);
        vecPtr.push_back(i);
        list.push_back(i);
    }

    for (int i = 0; i < size; i++) {
        vec.push_front(i);
        vecPtr.push_front(i);
        list.push_front(i);
    }

    int index = 546;
    printf("Vector at: %d\n", vec.at(index));
    printf("VectorPtr at: %d\n", vecPtr.at(index));
    printf("List at: %d\n", list.at(index));

    vec.insert_at(100, index);
    vecPtr.insert_at(100, index);
    list.insert_at(100, index);

    printf("Vector remove at: %d\n", vec.remove_at(index));
    printf("VectorPtr remove at: %d\n", *vecPtr.remove_at(index));
    printf("List remove at: %d\n", list.remove_at(index));

    return 0;
}
