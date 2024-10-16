/*
Создайте структуру `Student`, которая содержит поля: имя, возраст, средний балл.
Напишите функцию, которая принимает объект этой структуры и выводит информацию о студенте на экран.
*/
#include <iostream>

struct Student {
    char name[100];
    int age;
    float average_score;
};

void print_student_info(Student* stud);

int main() {
    Student student{"Ivan Ivanov", 21, 4.42};

    print_student_info(&student);

    return 0;
}

void print_student_info(Student *stud){
    printf("Student %s is %d years old and has an average score of %.2f\n",
        stud->name, stud->age, stud->average_score);
}
