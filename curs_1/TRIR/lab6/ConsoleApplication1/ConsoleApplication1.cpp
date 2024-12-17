// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define SIZE 20 // размер массива
//#define ROWS 6
//#define COLS 8
#include <stdio.h>

#define ROWS 6
#define COLS 8

int sOMEl(int* matrix, int rows, int cols, int K) {
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + j == K) {
                // Вычисление индекса в одномерном массиве с использованием арифметики указателей
                int index = i * cols + j;
                sum += matrix[index];
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

    // Вызов функции sOMEl, передавая указатель на первый элемент массива
    int sum1 = sOMEl(&X[0][0], ROWS, COLS, K);

    printf("The sum of the matrix elements with the sum of the indices equal to %d is equal to %d\n", k, sum1);

    return 0;
}




//int main() {
//    int A[SIZE]; // объявление массива
//    int i;
//    int sum =0;
//    int* str = A;
//    srand(time(NULL));
//    for (i = 0; i < SIZE; i++ ) {
//        A[i]=rand()%3;
//        printf("%d\n",A[i]);
//    }
//    for (i = 0; i < SIZE; i++) {
//        if (i % 2 == 0) {
//            sum += *(str + i);
//        }
//        else {
//            sum -= *(str + i);
//        }
//    }
//    printf("Alternating sum: %d\n", sum);
//}
