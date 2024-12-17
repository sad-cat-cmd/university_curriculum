// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include<string.h>
#define SIZE 100
int main()
{
    char array[SIZE];
    fgets(array, sizeof(array), stdin);
    char* word = strtok(array, " ");
    /*printf("%s", strtok(array, " "));*/
    while (word != NULL) {
        if (tolower(word[0]) == 'a') {
            printf("%s\n", word);
        }
        word = strtok(NULL, " " );
    }
    

}


