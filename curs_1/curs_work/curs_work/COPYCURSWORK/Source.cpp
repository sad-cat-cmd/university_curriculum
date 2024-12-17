#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include <dirent.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define size_name_file 15
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
void function_deleting_database_element(){

}
void fuction_deleting_database() {
	int number_fuction_menu;
	char name_file[size_name_file];
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
void sorting_database_items() {
	int number_in_list = 0, number_student_in_group = 0, number_function_menu, line = 0, number_str_elemets_in_line = 0;
	char name_student[50], name_group[8], date_of_receipt[12], temp_str[100], date_of_entry[9], file_name[size_name_file], temp_str_elemets_DB[50], *token;
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
		"Введите название базы данных, в которую вы хотите занести данные:");
		scanf_s("%s", &file_name, sizeof(file_name));
		strcat(file_name, ".txt");
		file_ptr = fopen(file_name, "r");
		if (file_ptr != NULL) {
			fclose(file_ptr);
			file_ptr = fopen(file_name, "a+");
			if (fgets(temp_str, 100, file_ptr) == NULL) {
				printf("---------------------------------------------------------------------------------\n"
				"База данных пуста\n"
				"---------------------------------------------------------------------------------\n"
				"ВВЕДИТЕ:\n"
				"1 --- для выхода в меню сортировки\n"
				"2 --- для внесения данных в эту базу данных"
				"3 --- для выхода в главное меню\n"
				"Команда: ");
				scanf_s("%d", &number_function_menu);
				if (number_function_menu == 1) {
					sorting_database_items();
				}
				if (number_function_menu == 2) {
					//
				}
				if (number_function_menu == 3) {
					recursive_menu();
				}
				if (number_function_menu!= 1 && number_function_menu != 2 && number_function_menu != 3) {
					//
				}
			}
			else {
				printf("---------------------------------------------------------------------------------\n"
					"ВВЕДИТЕ:\n"
					"1 --- для сортировки ФИО\n"
					"2 --- для сортировки по дате добавления в БД\n"
					"3 --- для сортировки по номеру группы\n"
					"4 --- для сортиртовки по дате изменения \n"
					"5 --- для выхода в главное меню\n"
					"----------------------------------------------------------\n"
					"КОМАНДА: ");
				scanf_s("%d", &number_function_menu);
				if (number_function_menu == 1) {
					printf("---------------------------------------------------------------------------------\n"
						"Введите способ сортировки ФИО:\n"
						"1 --- для сортировки по ФИО в алфавитном порядке\n"
						"2 --- для вывода данных об определенном студенте:\n"
						"3 --- для выхода в меню сортировки\n"
						"Команда:");
					scanf_s("%d", &number_function_menu);
					if (number_function_menu == 1) {
						while (fgets(temp_str, 100, file_ptr) != NULL) {
							line++;
							fgets(temp_str, 100, file_ptr);
							if (line >= 1) {
								fgets(temp_str, 100, file_ptr);
								removeSpaces(temp_str);
								printf("%s", temp_str);
								//token = strtok(temp_str, "|");
								//while (token != NULL) {
								//	printf("%s\n", token);
								//	if (number_str_elemets_in_line == 0) {
								//		str = token;
								//		while (*str != NULL) {
								//			number_in_list = *str - 48;
								//			str++;
								//		}
								//	}
								//	if (number_str_elemets_in_line == 1) {
								//		strcat(name_student, token);
								//	}
								//	if (number_str_elemets_in_line == 2) {
								//		strcat(name_student, token);
								//	}
								//	if (number_str_elemets_in_line == 3) {
								//		str = token;
								//		while (*str != NULL) {
								//			number_in_list = *str - 0x30;
								//			str++;
								//	    }
								//	}
								//	if (number_str_elemets_in_line == 4) {
								//		strcat(name_student, token);
								//	}
								//	if (number_str_elemets_in_line == 5) {
								//		strcat(name_student, token);
								//	}
								//	/*switch (number_str_elemets_in_line)
								//	{
								//	case 0:
								//		str = token;
								//		while (*str != NULL) {
								//			number_in_list = *str - 48;
								//			str++;
								//		}
								//	case 1:
								//		strcat(name_student, token);
								//	case 2:
								//		strcat(name_student, token);
								//	case 3:
								//		str = token;
								//		while (*str != NULL) {
								//			number_in_list = *str - 0x30;
								//			str++;
								//		}
								//	case 4:
								//		strcat(name_student, token);
								//	case 5:
								//		strcat(name_student, token);
								//	default:
								//		break;
								//	}*/
								//	token = strtok(NULL, "|");
								//	number_str_elemets_in_line++;

								//}
							}
						}
					}
					if (number_function_menu == 2) {

					}
					if (number_function_menu == 3) {
						sorting_database_items();
					}
				}
				if (number_function_menu == 2) {

				}
				if (number_function_menu == 3) {

				}
				if (number_function_menu == 4) {
					
				}
				if (number_function_menu == 5) {
					sorting_database_items();
				}
				else {
					printf("Была введена некоректная команда. Повторите попытку\n");
					//
				}
			}
		}
	}
	if (number_function_menu == 2) {
		recursive_menu();
	}
	else {
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char head3[] =
		"----------------------------------------------------------\n"
		"ВВЕДИТЕ:"
		"1 --- если данные введены коректно и вы готовы внести их в базу\n"
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
		/*switch (number_function_menu)
		{
		case 1:
			time_t mytime = time(NULL);
			struct tm* now = localtime(&mytime);
			strftime(date_of_entry, sizeof(date_of_entry), "%D", now);
			strcpy(name_student, name1);
			strcat(name_student, " ");
			strcat(name_student, name2);
			strcat(name_student, " ");
			strcat(name_student, name3);
			addNode(file_ptr, file_name, &head, number_in_list, name_student, name_group, number_student_in_group, date_of_receipt, date_of_entry, 0);
		case 2:
			number_in_list--;
		case 3:
			;
		default:
			break;
		}*/
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
				/*if (number_function_menu == 1) {
					printf("------------------------------------------------------------- \n Старое значение ФИО студента: %s \n ------------------------------------------------------------\n", name_student);
					printf("Новое значение ФИО студента: ");
					printf("Фамилия:");
					scanf_s("%s", name1, sizeof(name1));
					printf("Имя:  ");
					scanf_s("%s", name2, sizeof(name2));
					printf("Отчество:");
					scanf_s("%s", name3, sizeof(name3));
				}
				if (number_function_menu == 2) {
					printf("----------------------------------------------------------\n Старое значение названия группы: %s \n", name_group);
					printf("Новое значение названия группы: ");
					scanf_s("%s", &name_group);
				}
				if (number_function_menu == 3) {
					printf("----------------------------------------------------------\n Старое значение порядкового номера студента в группе: %d \n", number_student_in_group);
					printf("Новое значение названия группы: ");
					scanf_s("%d", &number_student_in_group);
				}
				if (number_function_menu == 4) {
					printf("----------------------------------------------------------\nСтарое значение даты поступления студента: %s \n", date_of_receipt);
					printf("Новое значение названия группы: ");
					scanf_s("%s", &date_of_receipt);
				}
				if (number_function_menu == 5) {
					printf("----------------------------------------------------------\n");
					printf("ВВЕДЕННЫЕ ДАННЫЕ: %d | %s %s %s | %s | %d | %s |\n", number_in_list + 1, name1, name2, name3, name_group, number_student_in_group, date_of_receipt);
					printf("----------------------------------------------------------\n");
					break;
				}
				if (number_function_menu == 6) {
					recursive_menu();
				}*/
			}
		}
		/*else {
			break;
		}*/
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
	int function_call_number = 0;
	int number_function_menu;
	const char head2[] =
		"----------------------------------------------------------\n"
		"ГЛАВНОЕ МЕНЮ\n"
		"----------------------------------------------------------\n"
		"ВВЕДИТЕ:\n"
		"1 --- для создания новой базы данных о студентах\n"
		"2 --- для просмотра уже существующих данных о студентах\n"
		"3 --- для добавления данных в базу данных\n"
		"4 --- для удаление конкретного элемента в базе данных\n"
		"5 --- для сортировки базы данных по конкретному параметру\n"
		"6 --- для удаления базы данных\n"
		"7 --- для закрытия программы <БД о студентах>\n"
		"----------------------------------------------------------\n"
		"КОМАНДА: ";
	const char head4[] =
		"ВВЕДИТЕ:"
		"";
	printf("%s", head2);
	scanf_s("%d", &number_function_menu);
	switch (number_function_menu) {
	case 1:
		database_creation_function();
	case 2:
		display_date_base();
	case 3:
		database_new_element();
	case 4:
		;
	case 5:
		sorting_database_items();
	case 6:
		fuction_deleting_database();
	case 7:
		return;
	default:
		printf("----------------------------------------------------------\nБыла введена некоректная команда, повторите попытку:\n----------------------------------------------------------\n");
		recursive_menu();
	}
}
int main() {
	/*setlocale(LC_ALL, "ru_RU.UTF-8");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("chcp 1251");
	const char head1[] =
		"----------------------------------------------------------\n"
		"ПРОГРАММА <БАЗА ДАННЫХ О СТУДЕНТАХ> ГОТОВА К РАБОТЕ\n"
		"----------------------------------------------------------\n";
	printf("%s", head1);
	recursive_menu();
}
