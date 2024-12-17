#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size_name_file 15
#define size_name_file_copy 21
typedef struct Node {
	int number_in_list;
	char name_student[50];
	char name_group[8];
	int number_student_in_group;
	char date_of_receipt[12];
	char date_of_entry[9];
	struct Node* next;
};
void database_new_element();
void enter_data(FILE* file_ptr, char file_name[], int number_of_repetitions);
void database_creation_function();
void recursive_menu();
void fuction_deleting_database();
void database_creation_function() {
	int number_function_menu = 0;
	FILE* file_ptr;
	char name_file[size_name_file];
	printf(
	"----------------------------------------------------------\n"
	"Меню создания новой базы данных о студентах\n"
	"----------------------------------------------------------\n");
	printf("----------------------------------------------------------\n");
	printf("Введите название файла. Учитывайте, что название файла может содержать только символы латинского и русского алфавита, а также знаки нижнего подчеркивания\n Название файла:");
	scanf_s("%s", &name_file, sizeof(name_file));
	printf("----------------------------------------------------------\n");
	strcat(name_file, ".txt");
	file_ptr = fopen(name_file, "a");
	if (file_ptr != NULL) {
		fclose(file_ptr);
		printf(
			"------------------------------------------------------------------------------------------\n"
			"База данных %s была создана и размещена в каталоге данной программы\n"
			"------------------------------------------------------------------------------------------\n", name_file);
		printf(
			"----------------------------------------------------------\n"
			"ВВЕДИТЕ:\n"
			"1 --- для внесения данных в эту базу данных\n"
			"2 --- для выхода в главное меню\n"
			"3 --- для создания еще одной базы данных"
			"----------------------------------------------------------\n"
			"КОМАНДА: ");
		scanf_s("%d", &number_function_menu);
		if (number_function_menu == 1) {
			/*enter_data();*/
		}
		if (number_function_menu == 3) {
			database_creation_function();
		}
		else {
			recursive_menu();
		}
	}
	else {
		printf(
			"----------------------------------------------------------------------------------------\n"
			"---Файл %s не был создан. Возможно был превышен допустимый размер названия данных или использован недопустимый символ\n"
			"----------------------------------------------------------------------------------------\n", file_ptr);
		printf("----------------------------------------------------------\n"
			"ВВЕДИТЕ:\n"
			"1 --- для повтора попытки создания базы данных\n"
			"2 --- для выхода в главное меню\n"
			"----------------------------------------------------------\n"
			"КОМАНДА: ");
		scanf_s("%d", &number_function_menu);
		if (number_function_menu == 1) {
		database_creation_function();
		}
		else {
			recursive_menu();
		}
	}
}
void database_new_element() {
	char temp_str[100];
	int isEmpty = 1;
	char file_name[size_name_file];
	int number_function_menu = 0;
	FILE* file_ptr;
	printf(
		"----------------------------------------------------------\n"
		"МЕНЮ ЗАНЕСЕНИЯ ДАННЫХ В БАЗУ ДАННЫХ\n"
		"----------------------------------------------------------\n"
		"ВВЕДИТЕ:\n"
		"1 --- для занесения данных\n"
		"2 --- для выхода в главное меню\n"
		"----------------------------------------------------------\n"
		"КОМАНДА: ");
		scanf_s("%d", &number_function_menu);
		if (number_function_menu == 1) {
			printf(
				"----------------------------------------------------------\n"
				"Введите название базы данных, в которую вы хотите занести данные:");
				scanf_s("%s", &file_name, sizeof(file_name));
				strcat(file_name, ".txt");
				file_ptr = fopen(file_name, "r+");
				if (file_ptr != NULL) {
					printf(
						"----------------------------------------------------------\n"
						"База данных существует и готова к записи \n ВВЕДИТЕ:\n 1 -- если хотите продолжить\n 2 -- если хотите отменить операцию\n КОМАНДА:  \n");
						scanf_s("%d", &number_function_menu, sizeof(number_function_menu));
						if (number_function_menu == 1) {
							if (fgets(temp_str, 100, file_ptr) == NULL) {
								fprintf(file_ptr,
									"-------------------------------------------------------------------------------------------\n"
									"| # |              ФИО                |Название группы | Номер в группе | Дата Поступления|\n"
									"-------------------------------------------------------------------------------------------\n");
							}
							fclose(file_ptr);
							file_ptr = fopen(file_name, "a");
							int number_of_repetitions;
							printf(
								"----------------------------------------------------------\n"
								"Введите количество заносимых строк в базу данных. Учитывайте, что в каждую строку базы данных нужно занести: ФИО студента, номер группы, дату поступления.\n"
								"Кол-во строк:");
							scanf_s("%d", &number_of_repetitions);
							enter_data(file_ptr, file_name, number_of_repetitions);
						}
						if (number_function_menu == 2) {
							database_new_element();
						}
						else {
							printf("Была введена некоректная команда. Вы возвращены в главное меню\n");
							recursive_menu();
						}
				}
					
		}
		if (number_function_menu == 2) {
			recursive_menu();
		}
		else {
			printf("База данных не существует.");
			recursive_menu();
		}
}
void database_element_editing_function() {

}
void fuction_deleting_database() {
	int number_fuction_menu;
	char name_file[size_name_file];
	printf("----------------------------------------------------------\n"
		"Меню удаления БД\n"
		"----------------------------------------------------------\n");
	printf("Введите название файла:");
	scanf_s("%s", &name_file, sizeof(name_file));
	strcat(name_file, ".txt");
	char* filePath = name_file;
	if (remove(name_file)==0 ) {
		printf(
			"----------------------------------------------------------\n"
			"Файл %s успешно удален \n"
			"----------------------------------------------------------\n", name_file);
		printf(
			"----------------------------------------------------------\n"
			"ВВЕДИТЕ:\n"
			"1 --- для выхода в главное меню\n"
			"----------------------------------------------------------\n"
			"КОМАНДА: "
		);
		scanf_s("%d", &number_fuction_menu, sizeof(number_fuction_menu));
		if (number_fuction_menu == 1) {
			recursive_menu();
		}
	}
	else {
		printf(
			"----------------------------------------------------------\n"
			"Не удалось удалить файл %s\n"
			"----------------------------------------------------------\n", name_file);
		printf("----------------------------------------------------------\n"
			"ВВЕДИТЕ:\n"
			"1 --- для повтора попытки удаления базы данных\n"
			"2 --- для выхода в главное меню\n"
			"----------------------------------------------------------\n"
			"КОМАНДА: ");
		scanf_s("%d", &number_fuction_menu, sizeof(number_fuction_menu));
		if (number_fuction_menu == 1) {
			database_creation_function();
		}
		else {
			recursive_menu();
		}
	}
}
void removeSpaces(char str[]) {
	int i, j = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}
void appendStringToArray(char* temp_str, char*** array, int* size) {
	(*array) = (char**)realloc((*array), ((*size) + 1) * sizeof(char*));
	(*array)[*size] = _strdup(temp_str);
	(*size)++;
}
void bubbleSort(char** arr, int n, int number_skip) {
	char* token_1, * token_2, * a = NULL, * b = NULL;
	char* str1 = 0, * str2 = 0;
	int k;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			k = 0;
			str1 = _strdup(arr[j]);
			str2 = _strdup(arr[j+1]);
			token_1 = strtok(str1, "|");
			while (token_1 != NULL) {
				token_1 = strtok(NULL, "|");
				if (k == number_skip) {
					//a = &token_1[0];
					a = _strdup(token_1);
				}
				k++;
			}
			k = 0;
			token_2 = strtok(str2, "|");
			while (token_2 != NULL) {
				token_2 = strtok(NULL, "|");
				if (k == number_skip) {
					//b = &token_2[0];
					b = _strdup(token_2);
				}
				k++;
			}
			if (strcmp(a, b) > 0) {
				char* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				}
		}
	}
}
void sorting_database_items() {
	int number_in_list = 0, number_student_in_group = 0, number_function_menu, line = 0, count_line_in_file = 0, i = 0;
	char name_student[50], name_group[8], date_of_receipt[12], temp_str[100], date_of_entry[9], file_name[size_name_file], temp_str_elemets_DB[50], *token, *array_str;
	//char* token, *str;
	FILE* file_ptr;
	printf("---------------------------------------------------------------------------------\n"
		"Меню сортировки информации в БД\n"
		"---------------------------------------------------------------------------------\n"
		"ВВЕДИТЕ:\n"
		"1 --- для выполнения сортировки\n"
		"2 --- для выхода в главное меню\n"
		"----------------------------------------------------------\n"
		"КОМАНДА: ");
	scanf_s("%d", &number_function_menu);
	if (number_function_menu == 1) {
		printf("---------------------------------------------------------------------------------\n"
		"Введите название базы данных, в которой следует выполнить сортировку:");
		scanf_s("%14s", &file_name, sizeof(file_name));
		strcat(file_name, ".txt");
		file_ptr = fopen(file_name, "r");
		if (file_ptr != NULL) {
			while (fgets(temp_str, 140, file_ptr) != NULL) {
				count_line_in_file++;
			}
			fclose(file_ptr);
			file_ptr = fopen(file_name, "a+");
			if (count_line_in_file <=3) {
				printf("---------------------------------------------------------------------------------\n"
				"База данных пуста\n"
				"---------------------------------------------------------------------------------\n"
				"ВВЕДИТЕ:\n"
				"1 --- для повторения попытки\n"
				"2 --- для выхода в главное меню\n"
				"Команда: ");
				scanf_s("%d", &number_function_menu);
				while (1) {
					switch (number_function_menu) {
					case 1:
						sorting_database_items();
					case 2:
						recursive_menu();
					default:
						printf("Была введена некоректная команда. Повторите попытку\n");
					}
				}
			}
			else {
				char** dynamicArray = NULL;
				int size = 0;
				while (fgets(temp_str, 100, file_ptr) != NULL) {
					line++;
					if (line >= 4) {
						removeSpaces(temp_str);
						appendStringToArray(temp_str, &dynamicArray, &size);
					}
				}
				printf("---------------------------------------------------------------------------------\nЭлементы БД:\n---------------------------------------------------------------------------------\n");
				for (i = 0; i < size; i++) {
					printf("%s\n", dynamicArray[i]);
				}
				printf("\n---------------------------------------------------------------------------------\n"
					"ВВЕДИТЕ:\n"
					"1 --- для сортировки ФИО\n"
					"2 --- для сортировки по дате поступления\n"
					"3 --- для сортировки по названию группы\n"
					"4 --- для сортиртовки по дате изменения \n"
					"5 --- для выхода в главное меню\n"
					"----------------------------------------------------------\n"
					"КОМАНДА: ");
				scanf_s("%d", &number_function_menu);
				if (number_function_menu == 1) {
					bubbleSort(dynamicArray, i, 0);
				}
				if (number_function_menu == 2) {
					bubbleSort(dynamicArray, i, 4);
				}
				if (number_function_menu == 3) {
					bubbleSort(dynamicArray, i, 1);
				}
				if (number_function_menu == 4) {
					bubbleSort(dynamicArray, i, 5);
				}
				if (number_function_menu == 5) {
					recursive_menu();
				}
				printf("---------------------------------------------------------------------------------\n"
					"Отсортированное значение:");
				for (int i = 0; i < size; i++) {
					//addSpacesBetweenCapitalLetters(dynamicArray[i]);
					printf("%s\n", dynamicArray[i]);
				}
				printf("--------------------------------------------------------------------------------\n");
				printf("\n---------------------------------------------------------------------------------\n"
					"ВВЕДИТЕ:\n"
					"1 --- для записи данного значения в новый файл\n"
					"2 --- для выхода в главное меню\n"
					"3 --- для продолжения сортировки другой базы данных\n"
					"----------------------------------------------------------\n"
					"КОМАНДА: ");
				scanf_s("%d", &number_function_menu);
				while (1) {
					switch (number_function_menu) {
					case 1: {
						printf("Введите название файла. Учитывайте, что название файла может содержать только символы латинского и русского алфавита, а также знаки нижнего подчеркивания\n Название файла:");
						scanf_s("%s", &file_name, sizeof(file_name));
						printf("----------------------------------------------------------\n");
						strcat(file_name, "copy.txt");
						file_ptr = fopen(file_name, "a");
						if (file_ptr == NULL) {
							printf("При работе с файлом произошла ошибка, пожалуйста повторите попытку\n");
							break;
						}
						else {
							for (i = 0; i < size; i++) {
								fprintf(file_ptr, "%s", dynamicArray[i]);
							}
							fclose(file_ptr);
							printf("Запись в файл %s прошла успешно", file_name);
							free(dynamicArray);
							recursive_menu();
						}
					}
					case 2: {
						free(dynamicArray);
						recursive_menu();
					}
					case 3: {
						sorting_database_items();
						free(dynamicArray);
					}
					default:
						printf("Была введена некоректная команда. Повторите попытку\n");
						break;
					}
				}
			}
		}
	}
	if (number_function_menu == 2) {
		recursive_menu();
	}
	if (number_function_menu == 3) {
		;;
	}
	if (number_function_menu != 1 && number_function_menu != 2) {
		printf("Была введена некоректная команда. Повторите попытку\n");
		sorting_database_items();
	}
}
Node* createNode(int number_in_list, char name_student[], char name_group[], int number_student_in_group, char date_of_receipt[], char date_of_entry[]) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number_in_list = number_in_list;
	strcpy(newNode->name_student, name_student);
	strcpy(newNode->name_group, name_group);
	newNode->number_student_in_group = number_student_in_group;
	strcpy(newNode->date_of_receipt, date_of_receipt);
	strcpy(newNode->date_of_entry, date_of_entry);
	newNode->next = NULL;
	return newNode;
}
void addNode(FILE* file_ptr, char file_name[], Node** head, int number_in_list, char name_student[], char name_group[], int number_student_in_group, char date_of_receipt[], char date_of_entry[], int free_condition) {
	Node* newNode = createNode(number_in_list, name_student, name_group, number_student_in_group, date_of_receipt, date_of_entry);
	if (free_condition == 0) {
		file_ptr = fopen(file_name, "a");
		fprintf(file_ptr, "|%-3d|", newNode->number_in_list);
		fprintf(file_ptr, "%-49s|", newNode->name_student);
		fprintf(file_ptr, "%-9s|", newNode->name_group);
		fprintf(file_ptr, "%-3d|", newNode->number_student_in_group);
		fprintf(file_ptr, "%-9s|", newNode->date_of_receipt);
		fprintf(file_ptr, "%-9s|", newNode->date_of_entry);
		fprintf(file_ptr, "\n");
		fclose(file_ptr);
		free(newNode);
	}
	else {
		if (*head == NULL) {
			*head = newNode;
		}
		else {
			Node* temp = *head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
}
void display_date_base() {
	char file_name[size_name_file];
	char temp_str[100];
	int number_function_menu;
	FILE* file_ptr;
	printf("---------------------------------------------------------------------------------\n"
		"Меню просмотра базы данных\n"
		"---------------------------------------------------------------------------------\n"
		"ВВЕДИТЕ:\n"
		"1 --- для просмотра существующей базы данных\n"
		"2 --- для выхода в главное меню\n"
		"----------------------------------------------------------\n"
		"КОМАНДА: ");
	scanf_s("%d", &number_function_menu);
	if (number_function_menu == 1) {
		printf("Введите название базы данных для чтения:");
		scanf_s("%s", &file_name, sizeof(file_name));
		strcat(file_name, ".txt");
		file_ptr = fopen(file_name, "r");
		if (file_ptr != NULL) {
			printf("--------------------------------------------------------\n БАЗА ДАННЫХ <%s>\n --------------------------------------------------------\n", file_name);
			while (fgets(temp_str, 100, file_ptr) != NULL) {
				printf("%s", temp_str);
			}
			printf("\n");
			fclose(file_ptr);
		}
		else {
			printf("-------------------------------------------------\nБаза данных <%s>не найдена\n-------------------------------------------------\n", file_name);
			printf("ВВЕДИТЕ:\n"
				"1 --- для повтора попытки\n"
				"2 --- для выхода в главное меню\n"
				"----------------------------------------------------------\n"
				"КОМАНДА: ");
			scanf_s("%d", &number_function_menu);
			if (number_function_menu == 1) {
				display_date_base();
			}
			if (number_function_menu == 2) {
				recursive_menu();
			}
			else {
				printf("Была введена некоректная команда. Повторите попытку\n");
				display_date_base();
			}
		}
	}
	if (number_function_menu == 2) {
		recursive_menu();
	}
	else {
		printf("-------------------------------------------------\nБыла введена некоректная команда. Повторите попытку\n-------------------------------------------------\n");
		display_date_base();
	}
}
void enter_data(FILE* file_ptr, char file_name[], int number_of_repetitions) {
	const char head3[] =
		"----------------------------------------------------------\n"
		"ВВЕДИТЕ:"
		"1 --- если данные введены корректно и вы готовы внести их в базу\n"
		"2 --- если хотите внести все введенные ранее в строку данные заново \n"
		"3 --- если хотите изменить конкретный параметр\n"
		"4 --- если хотите отменить введение и вернуться в главное меню\n"
		"----------------------------------------------------------\n";
	int number_in_list = 0;
	char name_student[50];
	char name1[20];
	char name2[15];
	char name3[15];
	char name_group[8];
	char date_of_entry[9];
	int number_student_in_group = 0;
	char date_of_receipt[12];
	int number_function_menu;
	for (number_in_list; number_in_list < number_of_repetitions; number_in_list++) {
		Node* head = NULL; 
		printf("----------------------------------------------------------\n");
		printf("ФИО студента: \n ");
		printf("Фамилия:");
		scanf_s("%s", name1, sizeof(name1));
		printf("Имя:  ");
		scanf_s("%s", name2, sizeof(name2));
		printf("Отчество:");
		scanf_s("%s", name3, sizeof(name3));
		printf("Название группы:  ");
		scanf_s("%s", name_group, sizeof(name_group));
		printf("Порядковый номер студента в группе  ");
		scanf_s("%d", &number_student_in_group);
		printf("Дата поступления:  ");
		scanf_s("%s", date_of_receipt, sizeof(date_of_receipt));
		printf("----------------------------------------------------------\n");
		printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s %s %s | %s | %d | %s |\n", number_in_list +1, name1, name2, name3, name_group, number_student_in_group, date_of_receipt);
		printf("----------------------------------------------------------\n");
		printf("%s", head3);
		printf("КОМАНДА:  ");
		scanf_s("%d", &number_function_menu);
		if (number_function_menu == 1) {
			time_t mytime = time(NULL);
			struct tm* now = localtime(&mytime);
			strftime(date_of_entry, sizeof(date_of_entry), "%D", now);
			strcpy(name_student, name1);
			strcat(name_student, " ");
			strcat(name_student, name2);
			strcat(name_student, " ");
			strcat(name_student, name3);
			addNode(file_ptr, file_name, &head, number_in_list, name_student, name_group, number_student_in_group, date_of_receipt, date_of_entry, 0);
		}
		if (number_function_menu == 2) {
			number_in_list--;
		}
		if (number_function_menu == 3) {
			while (number_function_menu != 5) {
				printf(
					"----------------------------------------------------------\n"
					"ВВЕДИТЕ : \n"
					"1 --- если хотите изменить ФИО студента\n"
					"2 --- если хотите изменить название группы\n"
					"3 --- ecли хотите изменить порядковый номер студента в группе\n"
					"4 --- если хотите изменить дату поступления\n"
					"5 --- если хотите вернуться к заполнению\n"
					"6 --- если хотите закончить ввод и вернуться в главное меню"
					"----------------------------------------------------------\n"
					"КОМАНДА:");
				scanf_s("%d", &number_function_menu);
				switch (number_function_menu)
				{
				case 1:
					printf("------------------------------------------------------------- \n Старое значение ФИО студента: %s \n ------------------------------------------------------------\n", name_student);
					printf("Новое значение ФИО студента: ");
					printf("Фамилия:");
					scanf_s("%s", name1, sizeof(name1));
					printf("Имя:  ");
					scanf_s("%s", name2, sizeof(name2));
					printf("Отчество:");
					scanf_s("%s", name3, sizeof(name3));
				case 2:
					printf("----------------------------------------------------------\n Старое значение названия группы: %s \n", name_group);
					printf("Новое значение названия группы: ");
					scanf_s("%s", &name_group);
				case 3:
					printf("----------------------------------------------------------\n Старое значение порядкового номера студента в группе: %d \n", number_student_in_group);
					printf("Новое значение порядкого номера студента: ");
					scanf_s("%d", &number_student_in_group);
				case 4:
					printf("----------------------------------------------------------\nСтарое значение даты поступления студента: %s \n", date_of_receipt);
					printf("Новое значение названия группы: ");
					scanf_s("%s", &date_of_receipt, sizeof(date_of_receipt));
				case 5:
					printf("----------------------------------------------------------\n");
					printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s %s %s | %s | %d | %s |\n", number_in_list + 1, name1, name2, name3, name_group, number_student_in_group, date_of_receipt);
					printf("----------------------------------------------------------\n");
					break;
				case 6:
					recursive_menu();
				default:
					printf("----------------------------------------------------------\nБыла введена некоректная команда\n----------------------------------------------------------\n");
				}
				printf("----------------------------------------------------------\n");
				printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s %s %s | %s | %d | %s |\n", number_in_list + 1, name1, name2, name3, name_group, number_student_in_group, date_of_receipt);
				printf("----------------------------------------------------------\n");
			}
		}
		if (number_in_list == number_of_repetitions) {
			printf(
				"----------------------------------------------------------\n"
				"Вы успешно ввели %d строк в базу данных\n"
				"----------------------------------------------------------\n"
				"ВВЕДИТЕ:\n"
				"1 --- для внесения дополнительных данных в базу\n"
				"2 --- для просмотра базы данных\n"
				"3 --- для выхода в главное меню"
				"----------------------------------------------------------\n"
				"КОМАНДА:", number_in_list);
			scanf_s("%d", &number_function_menu);
			if (number_function_menu == 1) {
				printf(
					"----------------------------------------------------------\n"
					"Введите количество заносимых в базу данных строк: \n");
				scanf_s("%d", &number_of_repetitions);
				/*enter_data(file_ptr, file_name, number_of_repetitions);*/
			}
			if (number_function_menu == 2) {

			}
			else {
				break;
			}
		}
	}
}
void recursive_menu() {
	int number_function_menu = 0;
	char str1[] = "%s";
	char str2[] = "%d";
    char head2[] =
		"----------------------------------------------------------\n"
		"ГЛАВНОЕ МЕНЮ\n"
		"----------------------------------------------------------\n"
		"ВВЕДИТЕ:\n"
		"1 --- для создания новой базы данных о студентах\n"
		"2 --- для просмотра уже существующих данных о студентах\n"
		"3 --- для добавления элементов в базу данных\n"
		"4 --- для сортировки базы данных по конкретному параметру\n"
		"5 --- для удаления базы данных\n"
		"6 --- для закрытия программы <БД о студентах>\n"
		"----------------------------------------------------------\n"
		"КОМАНДА: ";
	__asm {
		push esi;
		push eax;
		lea esi, head2;
		lea eax, str1;
		push esi;
		push eax;
		call printf;
		lea esi, number_function_menu;
		lea eax, str2;
		push esi;
		push eax;
		call scanf_s;;
		pop eax;
		pop esi;
	}
	/*printf("%s", head2);
	scanf_s("%d", &number_function_menu);*/
	switch (number_function_menu) {
	case 1:
		database_creation_function();
	case 2:
		display_date_base();
	case 3:
		database_new_element();
	case 4:
		sorting_database_items();
	case 5:
		fuction_deleting_database();
	case 6:
		return;
	default:
		printf("----------------------------------------------------------\nБыла введена некоректная команда, повторите попытку:\n----------------------------------------------------------\n");
		recursive_menu();
	}
}
int main() {
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("----------------------------------------------------------\n"
		   "ПРОГРАММА <БАЗА ДАННЫХ О СТУДЕНТАХ> ГОТОВА К РАБОТЕ\n"
		   "----------------------------------------------------------\n");
	recursive_menu();
	return 0;
}