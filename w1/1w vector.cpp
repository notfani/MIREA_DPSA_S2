#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

int prime(int x) {
	int k = 2;
	for (int i = 2; i < sqrt(x); ++i) {
		if (x % i == 0) {
			k += 2;
		}
	}
	return k;
}

void printVector(std::vector <int> a) {
	for (int i = 0; i < size(a); ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	std::setlocale(0, "ru");
	char menu;
	std::vector <int> a;
	std::vector <int> b;
	int k = 0;
	int x;

	std::cout
		<< "1. Добавить элемент в вектор\n"
		<< "2. Сформировать вектор из простых чисел основного вектора\n"
		<< "3. Удалить минимальный элемент из вектора\n"
		<< "4. Вывести вектор в консоль\n"
		<< "5. Определить кол-во чисел с делителями больше 3х штук\n"
		<< "6. -\n"
		<< "7. -\n"
		<< "8. -\n"
		<< "0. Выход\n"
		<< "________________________________\n";

	while (true) {
		std::cout << "Выберите действие\n";
		std::cin >> menu;
		switch (menu) {

		case '1':
			std::cout << "Введите число, которое хотите добавить:\n";
			std::cin >> x;
			a.push_back(x);
			std::cout << "Число успешно добавлено\n";
			break;

		case '2':
			sort(begin(a), end(a));
			for (int i = 0; i < size(a); ++i) {
				if (prime(a[i]) == 2) {
					b.push_back(a[i]);
				}
			}
			if (b.empty()) {
				std::cout << "Простых числе нет!\n";
			}
			else {
				std::cout << "Вектор создан!\n";
			}
			break;

		case '3':
			for (int i = 0; i < size(b) - 1; ++i) {
				if (b[i] != b[i + 1]) {
					std::erase(b, b[i]);
					break;
				}
				else std::erase(b, b[i]); 
			}
			break;

		case '4':
			char menu2;
			std::cout << "Выберите, какой вектор вы хотите вывести:\n"
				<< "a. Вывести основной вектор\n"
				<< "b. Вывести вектор с простыми числами\n";
			std::cin >> menu2;
			switch (menu2) {

			case 'a':
				printVector(a);
				std::cout << "Вектор a успешно выведен\n";
				break;

			case 'b':
				printVector(b);
				std::cout << "Вектор b успешно выведен\n";
				break;

			default:
				std::cout << "Неверно выбран массив!";
				break;
			}
			break;

		case '5':
			k = 0;
			for (int i = 0; i < size(a); ++i) {
				if (prime(a[i] >= 3)) {
					k += 1;
				}
			}
			std::cout << "Колличество таких чисел: " << k << "\n";
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '0':
			return false;
			break;
		default:
			std::cout << "Неверный ввод!\n";
			std::cout
				<< "1. Добавить элемент в вектор\n"
				<< "2. Сформировать вектор из простых чисел основного вектора\n"
				<< "3. Удалить минимальный элемент из вектора\n"
				<< "4. Вывести вектор в консоль\n"
				<< "5. Определить кол-во чисел с делителями больше 3х штук\n"
				<< "6. -\n"
				<< "7. -\n"
				<< "8. -\n"
				<< "9. -\n"
				<< "0. Выход";
			break;
		}
	}
}
