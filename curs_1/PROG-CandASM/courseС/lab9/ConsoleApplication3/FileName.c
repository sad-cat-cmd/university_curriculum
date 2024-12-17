// ConsoleApplication3.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define mes 5
#define MAX_ROWS 5
#define MAX_SIZE 15


typedef struct {
    int N;
    char name[10];
    int minSize;
    int maxSize;
    int age;
} Person;

void fillTable(Person table[], int size) {
    for (int i = 0; i < size; i++) {
        printf("������� ������ ��� ��������� %d:\n", i + 1);
        printf("��������: ");
        scanf("%s", &table[i].name);
        getchar();
        printf("����������� ������: ");
        scanf_s("%d", &table[i].minSize);
        printf("������������ ������: ");
        scanf_s("%d", &table[i].maxSize);
        printf("����: ");
        scanf_s("%d", &table[i].age);
    }
}

void printTable(Person table[], int size) {
    const char head[] =
        "+-------------------------------------------------------------+\n"
        "|   |                 |       ������       |                  |\n"
        "| # |    ��������     |----------+---------|       ����       |\n"
        "|   |                 |    ���   |  ����   |                  |\n"
        "+---+-----------------+----------+---------+------------------+\n";
    printf("%s", head);
    for (int i = 0; i < size; i++) {
        printf("| %1d | %-15s |   %-4d   |   %-4d  | %-15d  |\n", i + 1, table[i].name, table[i].minSize, table[i].maxSize, table[i].age);
        printf("+---+-----------------+----------+---------+------------------+\n");
    }
}
void swapTrans(struct Person *list, unsigned int size) {
    struct Person* buffer = malloc(sizeof(struct Person*));
    memcpy(buffer, list, sizeof(struct Person*));
    memcpy(list, list + (size - 1), sizeof(struct Person*));
    memcpy(list + (size - 1), buffer, sizeof(struct Person*));
    free(buffer);
}


//void swap(Person* a, Person* b) {
//    Person temp = *a;
//    *a = *b;
//    *b = temp;
//}
//void replacement(Person table[], int size) {
//    printf(" ������� � ����������� ������ ������ � ��������� ������:");
//    const char head[] =
//        "+-------------------------------------------------------------+\n"
//        "|   |                 |       ������       |                  |\n"
//        "| # |    ��������     |----------+---------|       ����       |\n"
//        "|   |                 |    ���   |  ����   |                  |\n"
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
    Person table[MAX_SIZE];
    int size;
    printf("������� ���������� ����� �������: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("������! �������� ������������ ������ �������.\n");
        return 0;
    }

    fillTable(table, size);
    printTable(table, size);
    /* replacement(table, size);*/
    return 0;
}