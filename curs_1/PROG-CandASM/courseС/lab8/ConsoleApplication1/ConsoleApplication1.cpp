// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 6
#define COLS 8

void fillRandom(int* arr) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            *(arr + i * COLS + j) = rand() % 100;
        }
    }
}
void printArray(int* arr) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d\t", *(arr + i * COLS + j));
        }
        printf("\n");
    }
}
int pri(int k) {
    int g;
    g = k - 2;
    return g;
}
int sOMEl(int matrix[ROWS][COLS], int K) {
    int sum = 0;
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
    int array[ROWS][COLS];
    int* ptr = &array[0][0];
    int k;
    int x;
    srand(time(NULL));
    fillRandom(ptr);
    printArray(ptr);
    scanf_s("%d", &k);
    x = pri(k);
    int sum1 = sOMEl(array, x);
    printf("The sum of the matrix elements with the sum of the indices equal to %d is equal to %d\n", k , sum1);
    return 0;
}

