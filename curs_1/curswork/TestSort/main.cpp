#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
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