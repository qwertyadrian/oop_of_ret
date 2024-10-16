/*
Определить структуры `Book`, содержащую название книги, автора, год издания.
Создать массив из нескольких книг и написать функцию, которая принимает массив и название книги
и возвращает номер книги в массиве. Если книга не обнаружена - возвращает `-1`.
*/
#include <iostream>
#include <cstring>

struct Book {
    char name[100];
    char author[100];
    int year;
};

int find_book(Book* books, int size, const char* name){
    for (size_t i = 0; i < size; i++){
        if (strcmp(books[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Book books[3] = {
        {"Book1", "Author1", 1985},
        {"Book2", "Author2", 2013},
        {"Book3", "Author3", 1998}
    };

    char name[] = "Book2";
    printf("Book %s is at index %d\n", name, find_book(books, 3, name));

    return 0;
}

