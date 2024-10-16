/*
Напишите программу, которая создаёт матрицу случайных чисел, запрашиваемого
пользователем размера. Выводит матрицу на экран.
Затем сортирует значения по всей матрице (по строкам). Выводит матрицу на экран.
*/
#include <iostream>

int fill_matrix(int rows, int cols, int** matrix);
void print_matrix(int rows, int cols, int** matrix);
void sort_matrix_row(int cols, int* row);
int* flatten(int rows, int cols, int** matrix);
void sort_matrix(int rows, int cols, int** matrix);

int main() {
    int rows, cols;

    printf("Enter matrix size: ");
    scanf("%d %d", &rows, &cols);

    // Инициализация матрицы
    int** matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    fill_matrix(rows, cols, matrix);
    print_matrix(rows, cols, matrix);
    // Сортировка в пределах строки
    for (size_t i = 0; i < rows; i++) {
        sort_matrix_row(cols, matrix[i]);
    }
    print_matrix(rows, cols, matrix);
    sort_matrix(rows, cols, matrix);
    print_matrix(rows, cols, matrix);

    // Очистка матрицы
    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

int fill_matrix(int rows, int cols, int** matrix){
    if (matrix == nullptr) {
        return -1;
    }
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            matrix[i][j] = rand() % 100;
        }
    }
    return 0;
}

void print_matrix(int rows, int cols, int **matrix){
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sort_matrix_row(int cols, int *row){
    if (row == nullptr) {
        return;
    }
    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0; j < cols - 1; j++) {
            if (row[j] > row[j + 1]){
                int temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

int* flatten(int rows, int cols, int **matrix){
    if (matrix == nullptr) {
        return nullptr;
    }
    int* flattened = new int[rows * cols];
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            flattened[i * cols + j] = matrix[i][j];
        }
    }
    return flattened;
}

void sort_matrix(int rows, int cols, int **matrix){
    int* flattened = flatten(rows, cols, matrix);
    if (flattened == nullptr) {
        return;
    }
    sort_matrix_row(rows * cols, flattened);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = flattened[i * cols + j];
        }
    }
    delete[] flattened;
}
