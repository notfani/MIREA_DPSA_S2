#include <iostream>
#include <format>
#include <vector>
#include <string>


struct student { 
	int student_id; //Номер зачётной книжки
	int task_number; //номер задания
	//Поля отвечающие за выполненные задачи (по-умол. false)
	bool problem_1 = false; //Задача 1
	bool problem_2 = false; //Задача 2
	bool problem_3 = false; //Задача 3

	student(int id) { //Параметризированный конструктор с пар-ом id
		student_id = id;
	}

	void DataInput() { //Ввод значений для полей структуры
		
		std::cout << "Введите номер задания: ";
		std::cin >> task_number;
		std::cout << "Введите решена ли задача\n";
		std::cout << "1. ";
		std::cin >> problem_1;
		std::cout << "2. ";
		std::cin >> problem_2;
		std::cout << "3. ";
		std::cin >> problem_3;
		
	}

	int sCount() { //Подсчёт баллов за задание
		int total_sum = 0;
		if (problem_1 == true) total_sum += 10;
		if (problem_2 == true) total_sum += 20;
		if (problem_3 == true) total_sum += 30;
		return total_sum;
	}

	void print() { //Вывод по шаблону
		std::cout << std::format("id студента: {:<5} | задание: {:<5} | задача 1: {:<5} | задача 2: {:<5} | задача 3: {:<5} | кол-во баллов: {:<5}\n",
			student_id, task_number, problem_1, problem_2, problem_3, sCount());
	}
};

struct resulting_table { 
	std::vector<student> rating_table; //Создание вектора со студентами
	
	resulting_table() = default; 

	void addToTable(student human) { //Метод добавления студента в начало вектора 
		rating_table.insert(rating_table.begin(), human);
	}

	void deleteFromTable(student human) { //Метод удаления студента из вектора
		int n = -1; //Инициализация индекса нужного студента 
		for (int i = 0; i < rating_table.size(); i++) { //Алгоритм поиска студента
			if (rating_table[i].student_id == human.student_id) {
				n = i;
				break;
			}
		}
		if (n == -1) { //Проверка на налиичие студента
			std::cout << "Неверный id\n";
			return;
		}

		rating_table.erase(rating_table.begin()+n); //Удаление студента по индексу в векторе
	}

	void printTable() { //Метод вывода таблицы
		for (int i = 0; i < rating_table.size(); i++) {
			rating_table[i].print();
		}
	}
};

student makeStudent(int student_id) { //Функция создающая объект структуры student
	student temp(student_id);
	return temp;
}

int main() {
	student student_1(00001), student_2(00002), student_3(00003), student_4(00004);
	resulting_table test_table;
	setlocale(LC_ALL, "ru");
	std::vector<student> zoo; //Объявление вектора всех студентов
	resulting_table total_table; //Объявление результирующей таблицы
	char menu;
	int student_id;
	bool flag = true;

	std::cout << "Меню:\n"
		<< "1. Добавить запись о студенте\n"
		<< "2. Удалить запись о студенте\n"
		<< "3. Вывести таблицу с результатами\n"
		<< "4. Демонстрация работы программы (не требует никакого ввода полей)\n"
		<< "0. Выход\n";

	while (true) {
		std::cout << "Выберите действие: ";
		std::cin >> menu;
		switch (menu) {
		case '1':
			flag = true;
			std::cout << "Введите id студента\n";
			std::cin >> student_id;
			for (int i = 0; i < zoo.size(); i++) {
				if (student_id == zoo[i].student_id) { //Проверка уникальности ключа
					std::cout << "Такой студент уже есть!!!\n";
					flag = false;
					break;
				}
			}
			if (flag) { //Создание объекта структуры и добавление в вектор
				zoo.push_back(makeStudent(student_id));
				zoo[zoo.size() - 1].DataInput();
				std::cout << "Студент успешно добавлен...\n";
				break;
			}
			else break;

		case '2':
			flag = true;
			std::cout << "Введите id студента\n";
			std::cin >> student_id;
			for (int i = 0; i < zoo.size(); i++) {
				if (student_id == zoo[i].student_id) { //Поиск нужного студента
					zoo.erase(zoo.begin() + i); //Удаление студента из вектора всех студентов
					std::cout << "Студент успешно удалён!\n";
					flag = false;
					break;
				}
			}
			if (flag) {
				std::cout << "Студент не найден!\n";
				break;
			}
			else break;

		case '3':
			for (int i = 0; i < zoo.size(); i++) {
				total_table.addToTable(zoo[i]);
			}
			total_table.printTable();
			break;

		case '4':
			std::cout << "Создам несколько студентов\n\n";
			//Студент не курильщика
			student_3.task_number = 3;
			student_3.problem_1 = 1;
			student_3.problem_2 = 0;
			student_3.problem_3 = 0;
			test_table.addToTable(student_3);

			//Студент хорошист
			student_2.task_number = 2;
			student_2.problem_1 = 1;
			student_2.problem_2 = 1;
			student_2.problem_3 = 0;
			test_table.addToTable(student_2);

			//Студент отличник
			student_1.task_number = 1;
			student_1.problem_1 = 1;
			student_1.problem_2 = 1;
			student_1.problem_3 = 1;
			test_table.addToTable(student_1);
			test_table.printTable();

			std::cout << "\nТеперь добавим студента в начало таблицы\n\n";

			//Добавляемы студент
			student_4.task_number = 4;
			student_4.problem_1 = 0;
			student_4.problem_2 = 0;
			student_4.problem_3 = 0;
			test_table.addToTable(student_4);
			test_table.printTable();
			
			std::cout << "\nКак видим этот студент не справился с контрольной по рисованию и теперь его надо отчислить\n\n";
			test_table.deleteFromTable(student_4);
			test_table.printTable();
			std::cout << "\n";


		case '0':
			std::cout << "До свидания!\n";
			return 1;

		default:
			std::cout << "Неверно выбран вариант!\n";
			std::cout << "Меню:\n"
				<< "1. Добавить запись о студенте\n"
				<< "2. Удалить запись о студенте\n"
				<< "3. Вывести таблицу с результатами\n"
				<< "4. Демонстрация работы программы (не требует никакого ввода полей)\n"
				<< "0. Выход\n";
		}
	}
}