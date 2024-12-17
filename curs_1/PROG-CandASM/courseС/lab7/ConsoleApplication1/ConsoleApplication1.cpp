// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
    char text[1000];  // Предполагаем, что текст не превышает 1000 символов

    printf("enter the text: ");
    fgets(text, sizeof(text), stdin);
    printf("Words starting with the letter 'a':\n");
    

    return 0;
}