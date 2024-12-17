#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
typedef struct Node {
	int number_in_list;
	char name_student[50];
	char name_group[8];
	int number_student_in_group;
	char date_of_receipt[12];
	char date_of_entry[9];
	struct Node* next;
};
#define size_name_file 15
#define size_name_file_copy 21
void database_new_element();
void removeSpaces(char str[]);
void enter_data(FILE* file_ptr, char file_name[], int number_of_repetitions);
void recursive_menu();

