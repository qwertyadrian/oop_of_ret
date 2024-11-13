#pragma once

#include "HeavyData.h"

struct HeavyListNode { // Связный список
    HeavyData data;
    HeavyListNode *next;
};

struct HeavyList {
    HeavyListNode *head; // Указатель на начало списка
    HeavyListNode *tail; // Указатель на конец списка
};

HeavyList initList() {
    HeavyList list;
    list.head = nullptr;
    list.tail = nullptr;
    return list;
}

bool list_is_empty(const HeavyList &list) {
    return list.head == nullptr;
}

HeavyData list_at(const HeavyList &list, const int index) {
    HeavyListNode *current = list.head;
    for (int i = 0; i < index; i++) {
        if (current == nullptr) {
            throw std::out_of_range("Index exceeds the length of the list");
        }
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Index exceeds the length of the list");
    }
    return current->data;
}

void list_push_back(HeavyList &list, HeavyData &data) {
    HeavyListNode *node = new HeavyListNode{data, nullptr};
    if (list_is_empty(list)) {
        list.head = node;
    } else {
        list.tail->next = node;
    }
    list.tail = node;
}

void list_push_front(HeavyList &list, HeavyData &data) {
    HeavyListNode *node = new HeavyListNode{data, list.head};
    list.head = node;
    if (list.tail == nullptr) {
        list.tail = node;
    }
}

void list_insert(HeavyList &list, const int index, HeavyData &data) {
    if (index == 0) {
        list_push_front(list, data);
        return;
    }
    HeavyListNode *current = list.head;
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            throw std::out_of_range("Index exceeds the length of the list");
        }
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Index exceeds the length of the list");
    }
    HeavyListNode *node = new HeavyListNode{data, current->next};
    current->next = node;
    if (node->next == nullptr) {
        list.tail = node;
    }
}

HeavyData list_remove(HeavyList &list, const int index) {
    if (list_is_empty(list)) throw std::out_of_range("Index exceeds the length of the list");

    if (index == 0) {
        HeavyListNode *node = list.head; // Сохраняем указатель на удаляемый элемент
        list.head = list.head->next; // Перемещаем указатель на следующий элемент
        HeavyData data = node->data; // Сохраняем данные удаляемого элемента
        delete node; // Удаляем элемент
        return data; // Возвращаем данные
    }
    HeavyListNode *current = list.head;
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            throw std::out_of_range("Index exceeds the length of the list");
        }
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        throw std::out_of_range("Index exceeds the length of the list");
    }
    HeavyListNode *node = current->next;
    current->next = node->next;
    if (current->next == nullptr) {
        list.tail = current;
    }
    HeavyData data = node->data;
    delete node;
    return data;
}

void list_move(HeavyList &list, const int from, const int to) {
    if (from == to) return;
    HeavyData data = list_remove(list, from);
    list_insert(list, to, data);
}

void list_swap(HeavyList &list, const int index1, const int index2) {
    if (index1 == index2) return;
    // Удаляем элемент с индексом index1
    HeavyData data1 = list_remove(list, index1);
    // Удаляем элемент с индексом index2 (если он больше index1, то уменьшаем на 1)
    HeavyData data2 = list_remove(list, index2 > index1 ? index2 - 1 : index2);
    // Вставляем элемент data2 на место index1
    list_insert(list, index1 > index2 ? index1 - 1 : index1, data2);
    // Вставляем элемент data1 на место index2
    list_insert(list, index2, data1);
}
