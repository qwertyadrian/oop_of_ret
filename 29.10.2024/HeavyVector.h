#pragma once

#include "HeavyData.h"

struct HeavyVector { // Векторное (последовательное) хранение
    int size = 0;
    int length = 1;
    HeavyData *data;
};

HeavyVector initVector(size_t size) { // Инициализирует вектор пустым
    HeavyVector *vector = new HeavyVector;
    vector->size = 0; // Количество элементов
    vector->length = size; // Длина вектора
    vector->data = new HeavyData[size];
    return *vector;
}

bool vector_is_empty(const HeavyVector &vec) { // Проверяет, пуст ли вектор
    return vec.size == 0;
}

void vector_resize(HeavyVector &vec, const int size) {
    HeavyData *new_data = new HeavyData[size];
    int min_size = (size < vec.size) ? size : vec.size;
    for (size_t i = 0; i < min_size; i++) {
        new_data[i] = vec.data[i];
    }
    delete[] vec.data;
    vec.data = new_data;

    if (size < vec.size) vec.size = size;
    vec.length = size;
}

HeavyData vector_pop_back(HeavyVector &vec) { // Удаляет последний элемент
    return vec.data[vec.size--];
}

HeavyData vector_at(const HeavyVector &vec, const int index) { // Возвращает элемент по индексу
    if (index < 0 || index >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    return vec.data[index];
}

void vector_push_back(HeavyVector &vec, const HeavyData &data) { // Добавляет элемент в конец вектора
    if (vec.size == vec.length) {
        vector_resize(vec, vec.length * 2);
    }
    vec.data[vec.size] = data;
    vec.size++;
}

void vector_insert_at(HeavyVector &vec, const HeavyData &data, const int index) { // Вставляет элемент по индексу
    if (vec.size == vec.length) {
        vector_resize(vec, vec.length * 2);
    }
    for (size_t i = vec.size; i > index; i--) {
        vec.data[i] = vec.data[i - 1];
    }
    vec.data[index] = data;
    vec.size++;
}

void vector_push_front(HeavyVector &vec, const HeavyData &data) { // Добавляет элемент в начало вектора
    vector_insert_at(vec, data, 0);
}

HeavyData vector_remove_at(HeavyVector &vec, const int index) { // Удаляет элемент по индексу
    if (index < 0 || index >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    HeavyData data = vec.data[index];
    for (size_t i = index; i < vec.size - 1; i++) {
        vec.data[i] = vec.data[i + 1]; // Сдвигаем элементы влево
    }
    vec.size--;
    return data;
}

void vector_swap(HeavyVector &vec, const int index1, const int index2) { // Меняет местами два элемента
    if (index1 < 0 || index1 >= vec.size || index2 < 0 || index2 >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    HeavyData temp = vec.data[index1];
    vec.data[index1] = vec.data[index2];
    vec.data[index2] = temp;
}

void vector_move(HeavyVector &vec, const int from, const int to) { // Перемещает элемент с позиции A на позицию B
    if (from < 0 || from >= vec.size || to < 0 || to >= vec.size) {
        throw std::out_of_range("Index exceeds the length of the vector");
    }
    if (from == to) return;
    HeavyData data = vector_remove_at(vec, from);
    vector_insert_at(vec, data, to);
}
