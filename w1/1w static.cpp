﻿#include <iostream>

const int MAX_SIZE = 10;

int printArray(int arrayToPrint[], int size) {
	std::cout << "Массив: ";
	for (int i = 0; i < size; i++)
		std::cout << arrayToPrint[i] << " ";
	std::cout << std::endl;
	return 0;
}

int addToArray(int staticArray[], int& size, int newNumber) {
	if (size >= MAX_SIZE) return -1;
	staticArray[size] = newNumber;
	size++;
	return 0;
}

int RemoveFromArray(int staticArray[], int& size, int position) {
	if (size <= 0) return -1;
	if (position >= size) return -2;
	for (int i = position; i < size - 1; i++)
		staticArray[i] = staticArray[i + 1];
	size--;
	return 0;
}

int prime(int x) {
	int k = 2;
	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0) {
			k += 2;
		}
	}
	return k;
}

int makeSecondArray(int Array[], int& size, int newNumber) {
	if (size >= MAX_SIZE) return -1;
	if (size == 0)	Array[size] = newNumber;
	for (int i = size - 1; i >= 0; --i) {
		if (Array[i] <= newNumber) {
			Array[i + 1] = newNumber;
			break;
		}
		else {
			Array[i + 1] = Array[i];
		}
	}
	size++;
	return 0;
}

int main() {
	std::setlocale(0, "ru");
	char menu;
	int x;
	int current_size1 = 0;
	int current_size2 = 0;
	int k;
	int Array[MAX_SIZE];
	int Array2[MAX_SIZE];

	std::cout
		<< "1. Добавить элемент в массив\n"
		<< "2. Сформировать массив из простых чисел основного массива\n"
		<< "3. Удалить минимальный элемент из массива\n"
		<< "4. Вывести массив в консоль\n"
		<< "5. Определить кол-во чисел с делителями больше 3х штук\n"
		<< "6. -\n"
		<< "7. -\n"
		<< "8. -\n"
		<< "0. Выход\n"
		<< "--------------------\n";

	while (true) {
		std::cout << "Выберите действие: ";
		std::cin >> menu;
		switch (menu) {

		case '1':
			std::cout << "Введите число, которое хотите добавить: ";
			std::cin >> x;
			if (addToArray(Array, current_size1, x) == -1) std::cout << "Массив полон!\n";
			else std::cout << "Число успешно добавлено\n";
			break;

		case '2':
			k = 0;
			for (int i = 0; i < current_size1; ++i) {
				if (prime(Array[i]) == 2) {
					if (makeSecondArray(Array2, current_size2, Array[i]) == -1) std::cout << "Массив полон!\n";
					else k += 1;
				}
			}
			if (k == 0) std::cout << "Простых числе нет!\n";
			else std::cout << "Массив успешно создан!\n";
			break;

		case '3':
			for (int i = 0; i < std::size(Array2) - 1; i++) {
				if (Array2[i] != Array2[i + 1]) {
					RemoveFromArray(Array2, current_size2, i);
					break;
				}
				else RemoveFromArray(Array2, current_size2, i);
			}
			std::cout << "Элемент успешно удалён\n";
			break;

		case '4':
			char menu2;
			std::cout << "Выберите, какой массив вы хотите вывести:\n"
				<< "1. Вывести основной массив\n"
				<< "2. Вывести массив с простыми числами\n";
			std::cin >> menu2;
			switch (menu2) {

			case '1':
				printArray(Array, current_size1);
				std::cout << "Массив a успешно выведен\n";
				break;

			case '2':
				printArray(Array2, current_size2);
				std::cout << "Массив b успешно выведен\n";
				break;

			default:
				std::cout << "Неверно выбран массив!\n";
				break;
			}
			break;

		case '5':
			k = 0;
			for (int i = 0; i < current_size1; ++i) {
				if (prime(Array[i]) >= 3) {
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
				<< "1. Добавить элемент в массив\n"
				<< "2. Сформировать вектор из простых чисел основного массива\n"
				<< "3. Удалить минимальный элемент из массива\n"
				<< "4. Вывести массив в консоль\n"
				<< "5. Определить кол-во чисел с делителями больше 3х штук\n"
				<< "6. -\n"
				<< "7. -\n"
				<< "8. -\n"
				<< "0. Выход\n"
				<< "--------------------\n";
			break;
		}
	}
}
