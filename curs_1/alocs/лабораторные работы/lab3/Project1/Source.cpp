#include <iostream>
int main() {
	float y, z;
	setlocale(LC_ALL, "RU");
	y = -1;
	z = -1;
	std::cout << "Начальные значение" << "\n";
	std::cout << "y=" << y << "\n";
	std::cout << "z=" << z << "\n";
	std::cout << "Мои значения" << "\n";
	std::cout << "с=" << y << "\n";
	std::cout << "d=" << z << "\n";
	std::cout << "Измененные значения - порядок увеличен на 8" << "\n";
	std::cout << "c=" << y << "\n";
	std::cout << "d=" << z << "\n";
	std::cout << "\n";
	std::cout << "stop";
}

