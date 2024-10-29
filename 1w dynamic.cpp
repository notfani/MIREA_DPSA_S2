#include <iostream>

int printArray(int arrayToPrint[], int size) {
	std::cout << "������: ";
	for (int i = 0; i < size; i++)
		std::cout << arrayToPrint[i] << " ";
	std::cout << std::endl;
	return 0;
}

int addToArray(int*& Array, int& size, int newNumber) {
	bool flag = false;
	if (size == 0)	Array[size] = newNumber;
	else {
		for (int i = 0; i <= size - 1; ++i) {
			if (Array[i] >= newNumber) {
				Array[i + 1] = Array[i];
				Array[i] = newNumber;
				flag = true;
				break;
			}
		}
		if (flag == false) Array[size] = newNumber;
	}
	size++;
	Array = (int*)realloc(Array, size * sizeof(int));
	return 0;
}

int RemoveFromArray(int* Array, int& size, int position) {
	if (size <= 0) return -1;
	if (position >= size) return -2;
	for (int i = position; i < size - 1; i++)
		Array[i] = Array[i + 1];
	size--;
	Array = (int*)realloc(Array, size * sizeof(int));
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

int main() {
	std::setlocale(0, "ru");
	char menu;
	int x;
	int current_size1 = 0;
	int current_size2 = 0;
	int k;
	int* Array1 = new int[current_size1];
	int* Array2 = new int[current_size2];

	std::cout
		<< "1. �������� ������� � ������\n"
		<< "2. ������������ ������ �� ������� ����� ��������� �������\n"
		<< "3. ������� ����������� ������� �� �������\n"
		<< "4. ������� ������ � �������\n"
		<< "5. ���������� ���-�� ����� � ���������� ������ 3� ����\n"
		<< "6. -\n"
		<< "7. -\n"
		<< "8. -\n"
		<< "0. �����\n"
		<< "--------------------\n";

	while (true) {
		std::cout << "�������� ��������\n";
		std::cin >> menu;
		switch (menu) {

		case '1':
			std::cout << "������� �����, ������� ������ ��������:\n";
			std::cin >> x;
			if (addToArray(Array1, current_size1, x) == -1) std::cout << "������ �����!\n";
			else std::cout << "����� ������� ���������\n";
			break;

		case '2':
			k = 0;
			for (int i = 0; i < current_size1; ++i) {
				if (prime(Array1[i]) == 2) {
					addToArray(Array2, current_size2, Array1[i]);
					k += 1;
				}
			}
			if (k == 0) std::cout << "������� ����� ���!\n";
			else std::cout << "������ ������� ������!\n";
			break;

		case '3':
			for (int i = 0; i < current_size2 - 1; i++) {
				if (Array2[i] != Array2[i + 1]) {
					RemoveFromArray(Array2, current_size2, i);
					break;
				}
				else RemoveFromArray(Array2, current_size2, i);
			}
			std::cout << "������� ������� �����\n";
			break;

		case '4':
			char menu2;
			std::cout << "��������, ����� ������ �� ������ �������:\n"
				<< "1. ������� �������� ������\n"
				<< "2. ������� ������ � �������� �������\n";
			std::cin >> menu2;
			switch (menu2) {

			case '1':
				printArray(Array1, current_size1);
				std::cout << "������ a ������� �������\n";
				break;

			case '2':
				printArray(Array2, current_size2);
				std::cout << "������ b ������� �������\n";
				break;

			default:
				std::cout << "������� ������ ������!\n";
				break;
			}
			break;

		case '5':
			k = 0;
			for (int i = 0; i < current_size1; ++i) {
				if (prime(Array1[i] >= 3)) {
					k += 1;
				}
			}
			std::cout << "����������� ����� �����: " << k << "\n";
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
			std::cout << "�������� ����!\n";
			std::cout
				<< "1. �������� ������� � ������\n"
				<< "2. ������������ ������ �� ������� ����� ��������� �������\n"
				<< "3. ������� ����������� ������� �� �������\n"
				<< "4. ������� ������ � �������\n"
				<< "5. ���������� ���-�� ����� � ���������� ������ 3� ����\n"
				<< "6. -\n"
				<< "7. -\n"
				<< "8. -\n"
				<< "0. �����\n"
				<< "--------------------\n";
			break;
		}
	}
}
