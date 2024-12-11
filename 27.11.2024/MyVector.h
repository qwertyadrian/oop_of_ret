#pragma once

#ifndef OOP_OF_RET_MYVECTOR_H
#define OOP_OF_RET_MYVECTOR_H

#include <iostream>

template<typename T>
class MyVector {
    private:
        int size = 0;
        int length = 1;
        T *data;

    public:
        MyVector(size_t size) {
            this->size = 0;
            this->length = size;
            this->data = new T[size];
        }

        MyVector(const MyVector &other) {
            size = other.size;
            length = other.length;
            data = new T[length];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        ~MyVector() {
            delete[] data;
        }

        MyVector & operator=(const MyVector &other) {
            if (this != &other) {
                delete[] data;
                size = other.size;
                length = other.length;
                data = new T[length];
                for (size_t i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        [[nodiscard]] bool is_empty() const {
            return size == 0;
        }

        void resize(const int size) {
            T *new_data = new T[size];
            int min_size = (size < this->size) ? size : this->size;
            for (size_t i = 0; i < min_size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;

            if (size < this->size) this->size = size;
            length = size;
        }

        T pop_back() {
            return data[size--];
        }

        T at(const int index) const {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index exceeds the length of the vector");
            }
            return data[index];
        }

        void push_back(const T &data) {
            if (size == length) {
                resize(length * 2);
            }
            this->data[size] = data;
            size++;
        }

        void insert_at(const T &data, const int index) {
            if (size == length) {
                resize(length * 2);
            }
            for (size_t i = size; i > index; i--) {
                this->data[i] = this->data[i - 1];
            }
            this->data[index] = data;
            size++;
        }

        void push_front(const T &data) {
            insert_at(data, 0);
        }

        T remove_at(const int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index exceeds the length of the vector");
            }
            T result = data[index];
            for (size_t i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
            return result;
        }

        void swap(const int index1, const int index2) {
            if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
                throw std::out_of_range("Index exceeds the length of the vector");
            }
            T temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }

        void move(const int from, const int to) {
            if (from < 0 || from >= size || to < 0 || to >= size) {
                throw std::out_of_range("Index exceeds the length of the vector");
            }
            if (from == to) return;
            T data = remove_at(from);
            insert_at(data, to);
        }

        [[nodiscard]] int get_size() const {
            return size;
        }

        [[nodiscard]] int get_length() const {
            return length;
        }
};

#endif // OOP_OF_RET_MYVECTOR_H
