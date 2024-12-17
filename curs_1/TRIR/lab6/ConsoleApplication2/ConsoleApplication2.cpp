// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#define ROWS 6
#define COLS 8

int sOMEl(int matrix[ROWS][COLS], int K) {
    int sum = 0;
   /* printf("%d \n ", **matrix);*/
    // Проходим по всей матрице и суммируем элементы с заданной суммой индексов
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i + j == K) {
                sum += *(*matrix + i * COLS + j);
            }
        }
    }

    return sum;
}

int main() {
    int X[ROWS][COLS] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16},
        {17, 18, 19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30, 31, 32},
        {33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48}
    };
    int k;
    scanf_s("%d", &k);
    int K = k - 2;
    int sum = sOMEl(X, K);

    printf("The sum of the matrix elements with the sum of the indices equal to %d is equal to %d\n", k, sum);
    return 0;
}
