// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define mas 5;
//void main(void)
//{
//    setlocale(LC_ALL, "Russian");
//    setlocale(LC_ALL, "rus");
//    int cp = GetConsoleCP();
//    const char shapka[] =
//        "+-------------------------------------------------------------+\n"
//        "|   |                 |       размер       |                  |\n"
//        "| # |  Название       |----------+---------|       цена       |\n"
//        "|   |                 | мин      | макс    |                  |\n"
//        "+---+-----------------+----------+---------+------------------+\n";
//    struct str
//    {
//        int num;
//        char name[10];
//        struct razm
//        {
//            char Min[3], Max[3];
//        }razm;
//        char price[10];
//    };
//    int i;
//
//    struct str odejda[5], temp;
//    for (i = 0; i < 5; i++)
//    {
//        odejda[i].num = i + 1;
//        printf("Введите название %d типа одежды: ", i + 1);
//        gets(odejda[i].name);
//        printf("Введите минимальный размер %d типа одежды: ", i + 1);
//        gets(odejda[i].razm.Min);
//        printf("Введите максимальный размер %d типа одежды:", i + 1);
//        gets(odejda[i].razm.Max);
//        printf("Введите цену на %d тип одежды : ", i + 1);
//        gets(odejda[i].price);
//
//    }
//    system("cls");
//    printf("%s", shapka);
//    SetConsoleCP(1251);
//    for (i = 0; i < 5; i++)
//    {
//        printf("| %-2d| %-16s| %-9s| %-8s| %-17s|\n", odejda[i].num, odejda[i].name, odejda[i].razm.Min, odejda[i].razm.Max, odejda[i].price);
//        printf("+-------------------------------------------------------------+\n");
//    }
//
//    temp = odejda[0];
//    odejda[0] = odejda[4];
//    odejda[4] = temp;
//    SetConsoleCP(cp);
//    printf("\n\n%s", shapka);
//    SetConsoleCP(1251);
//    for (i = 0; i < 5; i++)
//    {
//        printf("| %-2d| %-16s| %-9s| %-8s| %-17s|\n", odejda[i].num, odejda[i].name, odejda[i].razm.Min, odejda[i].razm.Max, odejda[i].price);
//        printf("+-------------------------------------------------------------+\n");
//    }
//    getch();
//}



//typedef struct Spec {
//    int Speed;
//    int Power;
//}info;
//typedef struct Data {
//    int number;
//    char Name[40];
//    struct Spec info;
//    int Volume;
//}Dat;
//Dat dt[100];
//int input(int s) {
//    system("chcp 1251");
//    system("cls");
//    for (int i = 0; i < S; i++) {
//        printf("Для %d строки\n", i + 1);
//        printf("Введите номер по порядку: ");
//        scanf_s("%d", &dt[i].number);
//        printf("Введите название: ");
//        scanf("%s", &dt[i].Name);
//        printf("Введите макс. Скорость: ");
//        scanf_s("%d", &dt[i].info.Speed);
//        printf("Введите мощность: ");
//        scanf_s("%d", &dt[i].info.Power);
//        printf("Введите объём двигателя: ");
//        scanf_s("%d", &dt[i].Volume);
//    }
//}
void strPRI(){
    int n;
    int mi = 3;
        int ma = 3;
    n = 1;
    struct str
    {
        int num;
        char name[10];
        struct razm
        {
            char Min[3], Max[3];
        }razm;
        int pies;
    }T1;
    printf("Введите название %d одежды (не боллее 10 символов):", n);
    fgets(T1.name, 10, stdin);
    printf("Введите Минимальный размер (европейский образец):\n");
    fgets(T1.razm.Min, 3, stdin);
    printf("Введите Максимальный размер (европейский образец):\n");
    fgets(T1.razm.Max, 3, stdin);
    printf("Введите цену в целых единицах измерения :\n");
    scanf_s("%d", &T1.pies);
}
int output() {
    const char head[] =
                "+-------------------------------------------------------------+\n"
                "|   |                 |       размер       |                  |\n"
                "| # |    название     |----------+---------|       цена       |\n"
                "|   |                 |    мин   |  макс   |                  |\n"
                "+---+-----------------+----------+---------+------------------+\n";
    setlocale(LC_ALL, "Russian");
    int s = 3;
    printf("%s", head);
    //for (int i = 0; i < s; i++) {
    //printf("| -15d| -8s| -5d| -9d|-15d|\n");
    //        /*dt[i].number, dt[i].name, dt[i].info.speed, dt[i].info.power, dt[i].volume);*/
    //}
    return 1;
}


int main()
{
    
    /*input(s);*/
    output();
    strPRI();
    return 0;
}
