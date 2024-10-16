/*
Напишите функцию сортировки массива из структур из `Task8` по среднему баллу.
*/
#include <iostream>

struct Student {
    char name[100];
    int age;
    float average_score;
};

void print_student_info(Student* stud);
void sort_students(Student* students, int size);

int main() {
    Student student{"Ivan Ivanov", 21, 4.42};
    Student students[3] = {
        student,
        {"John Smith", 22, 3.98},
        {"Dmitry Sidorov", 20, 4.21}
    };

    print_student_info(&student);
    sort_students(students, 3);
    for (size_t i = 0; i < 3; i++) {
        print_student_info(&students[i]);
    }

    return 0;
}

void print_student_info(Student *stud){
    printf("Student %s is %d years old and has an average score of %.2f\n", stud->name, stud->age, stud->average_score);
}

void sort_students(Student *students, int size){
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size - i - 1; j++){
            if (students[j].average_score > students[j + 1].average_score){
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

