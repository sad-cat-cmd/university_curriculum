// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define mes 5
#define MAX_ROWS 5
#define MAX_SIZE 15


struct Person {
    int N;
    char name[10];
    struct rt{
        int minSize;
        int maxSize;
    }size;

    int age;
};

void fillTable(struct Person* table, int size) {
    for (int i = 0; i < size; i++) {
        printf("Введите данные для структуры %d:\n", i + 1);
        printf("Название: ");
        scanf("%s", table->name);
        printf("Минимальный размер: ");
        scanf_s("%d", table->size.minSize);
        printf("Максимальный размер: ");
        scanf_s("%d", table->size.maxSize);
        printf("Цена: ");
        scanf_s("%d", table->age);
        table++;
    }
}

void printTable(struct Person* table, int size) {
    const char head[] =
        "+-------------------------------------------------------------+\n"
        "|   |                 |       размер       |                  |\n"
        "| # |    название     |----------+---------|       цена       |\n"
        "|   |                 |    мин   |  макс   |                  |\n"
        "+---+-----------------+----------+---------+------------------+\n";
    printf("%s", head);
    for (int i = 0; i < size; i++) {
        printf("| %1d | %-15s |   %-4d   |   %-4d  | %-15d  |\n", i + 1, table[i].name, table[i].minSize, table[i].size.maxSize, table[i].size.age);
        printf("+---+-----------------+----------+---------+------------------+\n");
        table++;
    }
}
//void swapTrans(struct Person* list, unsigned int size) {
//    struct Person* buffer = malloc(sizeof(struct Person));
//    memcpy(buffer, list, sizeof(struct Person));
//    memcpy(list, list + (size - 1), sizeof(struct Person));
//    memcpy(list + (size - 1), buffer, sizeof(struct Person));
//    free(buffer);
//}


//void swap(Person* a, Person* b) {
//    Person temp = *a;
//    *a = *b;
//    *b = temp;
//}
//void replacement(Person table[], int size) {
//    printf(" таблица с выполнением замены первой и последней строки:");
//    const char head[] =
//        "+-------------------------------------------------------------+\n"
//        "|   |                 |       размер       |                  |\n"
//        "| # |    название     |----------+---------|       цена       |\n"
//        "|   |                 |    мин   |  макс   |                  |\n"
//        "+---+-----------------+----------+---------+------------------+\n";
//    bool swapped = false;
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = i + 1; j > i; j--) {
//            if (table[j].age < table[i].age) {
//                swap(&table[i], &table[j]);
//                swapped = true;
//            }
//        }
//    }
//    if (swapped) {
// 
//        swap(&table[0], &table[size - 1]);
//    }
//    printf("%s", head);
//    for (int i = 0; i < size; i++) {
//        printf("| %1d | %-15s |   %-4d   |   %-4d  | %-15d  |\n", i + 1, table[i].name, table[i].minSize, table[i].maxSize, table[i].age);
//        printf("+---+-----------------+----------+---------+------------------+\n");
//
//    }
//}

int main() {
    setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "rus");
    struct Person table[MAX_SIZE];
    int size = 5;

    fillTable(table, size);
    printTable(table, size);
    struct Person tmp;
    tmp = table[0];
    table[0] = table[size - 1];
    table[size-1] = tmp;

   //swapTrans(table, size);
    printTable(table, size);
    /* replacement(table, size);*/
    return 0;
}
