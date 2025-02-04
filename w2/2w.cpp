#include <iostream>
#include <vector>

struct point {
	int x = 0;
	int y = 0;
};

std::vector<point> addDots(std::vector<point> plurality, int n) {
	point dot;
	for (int i = 0; i < n; i++) {
		std::cout << "������� x,y\n";
		std::cin >> dot.x;
		std::cin >> dot.y;
		plurality.push_back(dot);
	}
	return plurality;
}

void vectorOutput(std::vector<point> plurality, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "x: " << plurality[i].x << "\t" << "y: " << plurality[i].y;
	}
}

float countMedian(std::vector<point> plurality, int n) {
	float median;
	int temp_x, temp_y, median_index = n/2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (plurality[j].x > plurality[j + 1].x) {
				temp_x = plurality[j + 1].x;
				temp_y = plurality[j + 1].y;
				plurality[j + 1].x = plurality[j].x;
				plurality[j + 1].y = plurality[j].y;
				plurality[j].x = temp_x;
				plurality[j].y = temp_y;
			}
		}
	}
	median = plurality[median_index].x;
	return median;
}

int matrixInput(int** matrix, int matrix_size, int mode) {
	switch (mode) {
	case 0:
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				std::cin >> matrix[i][j];
			}
		}
		break;
	case 1:
		for (int i = 0; i < matrix_size; ++i) {
			for (int j = 0; j < matrix_size; ++j) {
				matrix[i][j] = 1 + std::rand() % 99;
			}
		}
		break;
	default:
		return -1;
	}
	return 0;
}

int tranposeMatrix(int** original_matrix, int** transposed_matrix, int matrix_size) {
	for (int i = 0; i < matrix_size; ++i) {
		for (int j = 0; j < matrix_size; j++) {
			transposed_matrix[i][j] = original_matrix[j][i];
		}
	}
	return 1;
}

void matrixOutput(int** matrix, int matrix_size) {
	for (int i = 0; i < matrix_size; ++i) {
		for (int j = 0; j < matrix_size; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "Ru");
	int matrix_size, menu2 , n, median;
	char menu;
	std::vector <point> plurality;
	point dot;


	std::cout << "������� ������ ���������� ������� �������: ";
	std::cin >> matrix_size;

	int** matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; ++i) {
		matrix[i] = new int[matrix_size];
	}

	int** transposed_matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; ++i) {
		transposed_matrix[i] = new int[matrix_size];
	}


	std::cout << "�������� ��������: \n"
		<< "1. ��������� ������� � ����������\n"
		<< "2. ��������� ������� ���������� �������\n"
		<< "3. ��������������� �������\n"
		<< "4. ����� �������������� �������\n"
		<< "5. ������� ������\n"
		<< "0. �����\n";

	while (true) {
		std::cout << "����: ";
		std::cin >> menu;
		switch (menu) {
		case '0':
			std::cout << "��������� ��������!\n";
			return 1;
		case '1':
			matrixInput(matrix, matrix_size, 0);
			std::cout << "������� ���������!\n";
			break;
		case '2':
			matrixInput(matrix, matrix_size, 1);
			std::cout << "������� ���������!\n";
			break;
		case '3':
			tranposeMatrix(matrix, transposed_matrix, matrix_size);
			std::cout << "������� ���������������!\n";
			break;
		case '4':
			std::cout << "������� n - ���-�� �����. ��������! n ������ ���� ��������!\n";
			std::cin >> n;
			if (n % 2 == 0) {
				std::cout << "n - ������! ������� ��������!\n";
				break;
			}
			else {
				plurality = addDots(plurality, n);
				median = countMedian(plurality, n);
				std::cout << "�������: " << median << "\n";
				break;
			}
		case '5':
			std::cout << "�������� ����� ������� �� ������ �������:\n"
				<< "1. ������������ �������\n"
				<< "2. ����������������� �������\n"
				<< "3. � ���������\n";
			std::cout << "����: ";
			std::cin >> menu2;
			switch (menu2)
			{
			case 1:
				matrixOutput(matrix, matrix_size);
				std::cout << "������� ��������\n";
				break;
			case 2:
				matrixOutput(transposed_matrix, matrix_size);
				std::cout << "������� ��������\n";
				break;
			case 3:
				std::cout << "�� �����:(\n";
				break;
			default:
				std::cout << "������ �������� ���!\n";
				break;
			}
			break;
		default:
			std::cout << "�������, �������� ��� ���!\n";
			std::cout << "�������� ��������: \n"
				<< "1. ��������� ������� � ����������\n"
				<< "2. ��������� ������� ���������� �������\n"
				<< "3. ��������������� �������\n"
				<< "4. ����� �������������� �������\n"
				<< "5. ������� ������\n"
				<< "0. �����\n";
		}
	}
}