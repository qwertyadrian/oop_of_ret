#pragma once

#include <iostream>
#include <string>

class Cat {
    private: // Модификатор доступа (сокрытие данных)
        int mass = 10;
        int age = 3;
        std::string *name;

    public:
        /*
         * Правило трёх
         * Если вы объявили один из трёх (конструктор, деструктор, конструктор копирования),
         * то нужно объявить остальные два
         */
        Cat(const std::string& name, int age, int mass) { // Конструктор класса (чаще всего описывается для инициализации динамической памяти)
            this->name = new std::string(name);
            this->age = age;
            this->mass = mass;
        };
        Cat(const Cat& other) { // Конструктор копирования
            this->name = new std::string(*other.name + "I");
            this->age = other.age;
            this->mass = other.mass;
        }
        ~Cat() { // Деструктор класса
            delete name; // Нужно для контроля памяти
        }

        Cat& operator=(const Cat& other) { // Перегрузка оператора присваивания
            *(this->name) = *(other.name);
            return *this;
        }

        void feed(int feedMass) {
            mass += feedMass;
        }

        int getMass() {return mass;}
        std::string getName() {return *name;} // getter
        void setName(const std::string& name) {
            printf("Old name: %s\t", this->name->c_str());
            printf("New name: %s\n", name.c_str());
            *(this->name) = name;
        } // setter
};