// ConsoleApplication1.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main()
{

	setlocale(LC_ALL, "russian");
	wchar_t string[100];
	wscanf_s(L"%ls", string);
	wprintf(L"%ls", string);
	//char vstr[] = "������ ���";
	//char str[10];
	//wchar_t ptr[10];
	////scanf_s("%ls", str, 2);
	////wprintf(L"%ls", str );
	//wscanf_s(L"ls", ptr, 10);
	//printf("%s", vstr);
	//wprintf(L"%ls", ptr);
	/*wchar_t str[10];
	wchar_t ptr[10];
	wscanf_s(L"%ls", str);
	wprintf(L"%ls", str);
	setlocale(LC_ALL, "russian");
	wscanf_s(L"%s", ptr);
	wprintf(L"%ls", ptr);*/

	//int number_of_repetitions;
	//printf("������� ���������� �����:");
	//scanf_s("%d", &number_of_repetitions);
	//const char head3[] =
	//	"----------------------------------------------------------\n"
	//	"�������:"
	//	"1 --- ���� ������ ������� �������� � �� ������ ������ �� � ����\n"
	//	"2 --- ���� ������ ������ ��� ��������� ����� � ������ ������ ������ \n"
	//	"3 --- ���� ������ �������� ���������� ��������\n"
	//	"4 --- ���� ������ �������� �������� � ��������� � ������� ����\n"
	//	"----------------------------------------------------------\n";
	//int number_in_list = 0;
	//char name_student[50];
	//char name1[20];
	//char name2[15];
	//char name3[15];
	//char name_group[11];
	//int number_student_in_group = 0;
	//char date_of_receipt[10];
	//int number_function_menu;
	//for (number_in_list; number_in_list < number_of_repetitions; number_in_list++) {
	//	printf("----------------------------------------------------------\n");
	//	printf("��� ��������: \n ");
	//	printf("�������:");
	//	scanf_s("%s", name1, sizeof(name1));
	//	printf("���:  ");
	//	scanf_s("%s", name2, sizeof(name2));
	//	printf("��������:");
	//	scanf_s("%s", name3, sizeof(name3));
	//	printf("�������� ������:  ");
	//	scanf_s("%s", name_group, sizeof(name_group));
	//	printf("���������� ����� �������� � ������  ");
	//	scanf_s("%d", &number_student_in_group);
	//	printf("���� �����������:  ");
	//	scanf_s("%s", date_of_receipt, sizeof(date_of_receipt));
	//	printf("----------------------------------------------------------\n");
	//	printf("��������� ������: %d | %s %s %s | %s | %d | %s |\n", number_in_list, name1, name2, name3, name_group, number_student_in_group, date_of_receipt);
	//	printf("----------------------------------------------------------\n");
	//	printf("%s", head3);
	//	printf("�������:  ");
	//	scanf_s("%d", &number_function_menu);
	//	if (number_function_menu == 1) {
	//		strcpy(name_student, name1);
	//		strcat(name_student, " ");
	//		strcat(name_student, name2);
	//		strcat(name_student, " ");
	//		strcat(name_student, name3);
	//		printf("%s", name_student);
	//		//addNode(file_ptr, file_name, &head, number_in_list, name_student, name_group, number_student_in_group, date_of_receipt);
	//	}
	//	if (number_function_menu == 2) {
	//		number_in_list--;
	//	}
	//	if (number_function_menu == 3) {
	//		while (number_function_menu != 5) {
	//			printf(
	//				"----------------------------------------------------------\n"
	//				"������� : \n"
	//				"1 --- ���� ������ �������� ��� ��������\n"
	//				"2 --- ���� ������ �������� �������� ������\n"
	//				"3 --- ec�� ������ �������� ���������� ����� �������� � ������\n"
	//				"4 --- ���� ������ �������� ���� �����������\n"
	//				"5 --- ���� ������ ��������� � ����������\n"
	//				"----------------------------------------------------------\n"
	//				"�������:");
	//			scanf_s("%d", &number_function_menu);
	//			if (number_function_menu == 1) {
	//				printf("----------------------------------------------------------\n ������ �������� ��� ��������: %s \n", name_student);
	//				printf("����� �������� ��� ��������: ");
	//				scanf_s("%s", &name_student);
	//			}
	//			if (number_function_menu == 2) {
	//				printf("----------------------------------------------------------\n ������ �������� �������� ������: %s \n", name_group);
	//				printf("����� �������� �������� ������: ");
	//				scanf_s("%s", &name_group);
	//			}
	//			if (number_function_menu == 3) {
	//				printf("----------------------------------------------------------\n ������ �������� ����������� ������ �������� � ������: %d \n", number_student_in_group);
	//				printf("����� �������� �������� ������: ");
	//				scanf_s("%d", &number_student_in_group);
	//			}
	//			if (number_function_menu == 4) {
	//				printf("----------------------------------------------------------\n������ �������� ���� ����������� ��������: %s \n", date_of_receipt);
	//				printf("����� �������� �������� ������: ");
	//				scanf_s("%s", &date_of_receipt);
	//			}
	//			if (number_function_menu == 5) {
	//				printf("----------------------------------------------------------\n");
	//				printf("��������� ������: %d | %s | %s | %d | %s |\n", number_in_list, name_student, name_group, number_student_in_group, date_of_receipt);
	//				printf("----------------------------------------------------------\n");
	//				break;
	//			}
	//			printf("----------------------------------------------------------\n");
	//			printf("��������� ������: %d | %s | %s | %d | %s |\n", number_in_list, name_student, name_group, number_student_in_group, date_of_receipt);
	//			printf("----------------------------------------------------------\n");
	//		}
	//	}
	//	/*else {
	//		break;
	//	}*/
	//	if (number_in_list == number_of_repetitions) {
	//		printf(
	//			"----------------------------------------------------------\n"
	//			"�� ������� ����� %d ����� � ���� ������\n"
	//			"----------------------------------------------------------\n"
	//			"�������:\n"
	//			"1 --- ��� �������� �������������� ������ � ����\n"
	//			"2 --- ��� ��������� ���� ������\n"
	//			"3 --- ��� ������ � ������� ����"
	//			"----------------------------------------------------------\n"
	//			"�������:", number_in_list);
	//		scanf_s("%d", &number_function_menu);
	//		if (number_function_menu == 1) {
	//			printf(
	//				"----------------------------------------------------------\n"
	//				"������� ���������� ��������� � ���� ������ �����: \n");
	//			scanf_s("%d", &number_of_repetitions);
	//			/*enter_data(file_ptr, file_name, number_of_repetitions);*/
	//		}
	//		if (number_function_menu == 2) {

	//		}
	//		else {
	//			break;
	//		}
	//	}
	//}
}


// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
