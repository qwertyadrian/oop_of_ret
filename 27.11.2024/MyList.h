#pragma once

#ifndef OOP_OF_RET_MYLIST_H
#define OOP_OF_RET_MYLIST_H

#include <iostream>

template<typename T>
class MyList {
    private:
        struct HeavyListNode {
            T data;
            HeavyListNode *next;
        };

        HeavyListNode *head;
        HeavyListNode *tail;

    public:
        MyList() {
            head = nullptr;
            tail = nullptr;
        }

        MyList(const MyList &other) {
            HeavyListNode *current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }

        ~MyList() {
            HeavyListNode *current = head;
            while (current != nullptr) {
                HeavyListNode *next = current->next;
                delete current;
                current = next;
            }
        }

        MyList & operator=(const MyList &other) {
            if (this != &other) {
                HeavyListNode *current = head;
                while (current != nullptr) {
                    HeavyListNode *next = current->next;
                    delete current;
                    current = next;
                }
                head = nullptr;
                tail = nullptr;
                current = other.head;
                while (current != nullptr) {
                    push_back(current->data);
                    current = current->next;
                }
            }
            return *this;
        }

        [[nodiscard]] bool is_empty() const {
            return head == nullptr;
        }

        T at(const int index) {
            HeavyListNode *current = head;
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

        void push_back(T &data) {
            HeavyListNode *node = new HeavyListNode{data, nullptr};
            if (is_empty()) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }

        void push_front(T &data) {
            HeavyListNode *node = new HeavyListNode{data, head};
            head = node;
            if (tail == nullptr) {
                tail = node;
            }
        }

        void insert_at(const T &data, const int index) {
            if (index == 0) {
                push_front((int &)(int &)data);
                return;
            }
            HeavyListNode *current = head;
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
                tail = node;
            }
        }

        T remove_at(const int index) {
            if (is_empty())
                throw std::out_of_range("Index exceeds the length of the list");

            if (index == 0) {
                HeavyListNode *node = head;
                head = head->next;
                T data = node->data;
                delete node;
                return data;
            }
            HeavyListNode *current = head;
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
            if (node->next == nullptr) {
                tail = current;
            }
            T data = node->data;
            delete node;
            return data;
        }

        void move(const int from, const int to) {
            if (from == to) return;
            T data = remove(from);
            insert(to, data);
        }

        void swap(const int index1, const int index2) {
            if (index1 == index2) return;
            T data1 = remove(index1);
            T data2 = remove(index2 > index1 ? index2 - 1 : index2);
            insert(index1 > index2 ? index1 - 1 : index1, data1);
            insert(index2, data2);
        }
};

#endif // OOP_OF_RET_MYLIST_H
