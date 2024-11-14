#include <iostream>
#include <chrono>

#include "HeavyData.h"
#include "HeavyVector.h"
#include "HeavyVectorPtr.h"
#include "HeavyList.h"

/*
    Добавление в начало
    Добавление в конец
    Произвольный доступ
    Произвольная вставка (операции вставки)
    Удаление по произвольному индексу
    Перемещение элемента с позиции A на позицию Б
    Перемена мест двух элементов
*/

// Псевдоним типа данных
typedef std::chrono::microseconds my_time;
// using my_time = std::chrono::microseconds;

std::chrono::steady_clock::time_point startTime;
std::chrono::steady_clock::time_point endTime;
my_time durationTime;

void resetTime() {
    startTime = std::chrono::steady_clock::now();
}

void fixCurrTime() {
    endTime = std::chrono::steady_clock::now();
    durationTime = std::chrono::duration_cast<my_time>(endTime - startTime);
}

int main() {

    resetTime();
    fixCurrTime();
    printf("Time skipped: %ld\n\n", durationTime.count());

    HeavyData data;
    for (size_t i = 0; i < HEAVY_SIZE; i++) {
        data.heavyDouble[i] = i;
        data.heavyInt[i] = i;
    }

    printf("Замер времени инициализации структур данных\n");

    resetTime();
    HeavyVector vector = initVector(100);
    fixCurrTime();
    printf("Vector init: %ld\n", durationTime.count());

    resetTime();
    HeavyVectorPtr vectorPtr = initVectorPtr(100);
    fixCurrTime();
    printf("VectorPtr init: %ld\n", durationTime.count());

    resetTime();
    HeavyList list = initList();
    fixCurrTime();
    printf("List init: %ld\n\n", durationTime.count());

    printf("Замер времени добавления элементов в конец\n");

    resetTime();
    for (size_t i = 0; i < 1000; ++i) {
        vector_push_back(vector, data);
    }
    fixCurrTime();
    printf("Vector push back: %ld\n", durationTime.count());

    resetTime();
    for (size_t i = 0; i < 1000; ++i) {
        vector_ptr_push_back(vectorPtr, data);
    }
    fixCurrTime();
    printf("VectorPtr push back: %ld\n", durationTime.count());

    resetTime();
    for (size_t i = 0; i < 1000; ++i) {
        list_push_back(list, data);
    }
    fixCurrTime();
    printf("List push back: %ld\n\n", durationTime.count());

    printf("Замер времени добавления элементов в начало\n");

    resetTime();
    for (size_t i = 0; i < 1000; ++i) {
        vector_push_front(vector, data);
    }
    fixCurrTime();
    printf("Vector push front: %ld\n", durationTime.count());

    resetTime();
    for (size_t i = 0; i < 1000; ++i) {
        vector_ptr_push_front(vectorPtr, data);
    }
    fixCurrTime();
    printf("VectorPtr push front: %ld\n", durationTime.count());

    resetTime();
    for (size_t i = 0; i < 1000; ++i) {
        list_push_front(list, data);
    }
    fixCurrTime();
    printf("List push front: %ld\n\n", durationTime.count());

    printf("Замер времени произвольного доступа\n");
    int i = 546;

    resetTime();
//    for (size_t i = 0; i < 1000; ++i) {
        vector_at(vector, i);
//    }
    fixCurrTime();
    printf("Vector at: %ld\n", durationTime.count());

    resetTime();
//    for (size_t i = 0; i < 1000; ++i) {
        vector_ptr_at(vectorPtr, i);
//    }
    fixCurrTime();
    printf("VectorPtr at: %ld\n", durationTime.count());

    resetTime();
//    for (size_t i = 0; i < 1000; ++i) {
        list_at(list, i);
//    }
    fixCurrTime();
    printf("List at: %ld\n\n", durationTime.count());

    printf("Замер времени произвольной вставки\n");

    resetTime();
    vector_insert_at(vector, data, i);
    fixCurrTime();
    printf("Vector insert at: %ld\n", durationTime.count());

    resetTime();
    vector_ptr_insert_at(vectorPtr, data, i);
    fixCurrTime();
    printf("VectorPtr insert at: %ld\n", durationTime.count());

    resetTime();
    list_insert(list, i, data);
    fixCurrTime();
    printf("List insert: %ld\n\n", durationTime.count());

    printf("Замер времени удаления элементов\n");

    resetTime();
    vector_remove_at(vector, i);
    fixCurrTime();
    printf("Vector remove at: %ld\n", durationTime.count());

    resetTime();
    vector_ptr_remove_at(vectorPtr, i);
    fixCurrTime();
    printf("VectorPtr remove at: %ld\n", durationTime.count());

    resetTime();
    list_remove(list, i);
    fixCurrTime();
    printf("List remove: %ld\n\n", durationTime.count());

    return 0;
};