// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	//char vstr[] = "Привет Мир";
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
	//printf("Введите количество строк:");
	//scanf_s("%d", &number_of_repetitions);
	//const char head3[] =
	//	"----------------------------------------------------------\n"
	//	"ВВЕДИТЕ:"
	//	"1 --- если данные введены коректно и вы готовы внести их в базу\n"
	//	"2 --- если хотите внести все введенные ранее в строку данные заново \n"
	//	"3 --- если хотите изменить конкретный параметр\n"
	//	"4 --- если хотите отменить введение и вернуться в главное меню\n"
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
	//	printf("ФИО студента: \n ");
	//	printf("Фамилия:");
	//	scanf_s("%s", name1, sizeof(name1));
	//	printf("Имя:  ");
	//	scanf_s("%s", name2, sizeof(name2));
	//	printf("Отчество:");
	//	scanf_s("%s", name3, sizeof(name3));
	//	printf("Название группы:  ");
	//	scanf_s("%s", name_group, sizeof(name_group));
	//	printf("Порядковый номер студента в группе  ");
	//	scanf_s("%d", &number_student_in_group);
	//	printf("Дата поступления:  ");
	//	scanf_s("%s", date_of_receipt, sizeof(date_of_receipt));
	//	printf("----------------------------------------------------------\n");
	//	printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s %s %s | %s | %d | %s |\n", number_in_list, name1, name2, name3, name_group, number_student_in_group, date_of_receipt);
	//	printf("----------------------------------------------------------\n");
	//	printf("%s", head3);
	//	printf("КОМАНДА:  ");
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
	//				"ВВЕДИТЕ : \n"
	//				"1 --- если хотите изменить ФИО студента\n"
	//				"2 --- если хотите изменить название группы\n"
	//				"3 --- ecли хотите изменить порядковый номер студента в группе\n"
	//				"4 --- если хотите изменить дату поступления\n"
	//				"5 --- если хотите вернуться к заполнению\n"
	//				"----------------------------------------------------------\n"
	//				"КОМАНДА:");
	//			scanf_s("%d", &number_function_menu);
	//			if (number_function_menu == 1) {
	//				printf("----------------------------------------------------------\n Старое значение ФИО студента: %s \n", name_student);
	//				printf("Новое значение ФИО студента: ");
	//				scanf_s("%s", &name_student);
	//			}
	//			if (number_function_menu == 2) {
	//				printf("----------------------------------------------------------\n Старое значение названия группы: %s \n", name_group);
	//				printf("Новое значение названия группы: ");
	//				scanf_s("%s", &name_group);
	//			}
	//			if (number_function_menu == 3) {
	//				printf("----------------------------------------------------------\n Старое значение порядкового номера студента в группе: %d \n", number_student_in_group);
	//				printf("Новое значение названия группы: ");
	//				scanf_s("%d", &number_student_in_group);
	//			}
	//			if (number_function_menu == 4) {
	//				printf("----------------------------------------------------------\nСтарое значение даты поступления студента: %s \n", date_of_receipt);
	//				printf("Новое значение названия группы: ");
	//				scanf_s("%s", &date_of_receipt);
	//			}
	//			if (number_function_menu == 5) {
	//				printf("----------------------------------------------------------\n");
	//				printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s | %s | %d | %s |\n", number_in_list, name_student, name_group, number_student_in_group, date_of_receipt);
	//				printf("----------------------------------------------------------\n");
	//				break;
	//			}
	//			printf("----------------------------------------------------------\n");
	//			printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s | %s | %d | %s |\n", number_in_list, name_student, name_group, number_student_in_group, date_of_receipt);
	//			printf("----------------------------------------------------------\n");
	//		}
	//	}
	//	/*else {
	//		break;
	//	}*/
	//	if (number_in_list == number_of_repetitions) {
	//		printf(
	//			"----------------------------------------------------------\n"
	//			"Вы успешно ввели %d строк в базу данных\n"
	//			"----------------------------------------------------------\n"
	//			"ВВЕДИТЕ:\n"
	//			"1 --- для внесения дополнительных данных в базу\n"
	//			"2 --- для просмотра базы данных\n"
	//			"3 --- для выхода в главное меню"
	//			"----------------------------------------------------------\n"
	//			"КОМАНДА:", number_in_list);
	//		scanf_s("%d", &number_function_menu);
	//		if (number_function_menu == 1) {
	//			printf(
	//				"----------------------------------------------------------\n"
	//				"Введите количество заносимых в базу данных строк: \n");
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


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
