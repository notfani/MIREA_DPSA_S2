#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

std::vector<std::string> SplitText(std::string sentence) { //Разбиваем текст на слова
	std::vector<std::string> words;
	std::string word = "";

	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == ' ') {
			words.push_back(word);
			word = "";
		}
		else word += sentence[i];
	}
	words.push_back(word);

	return words;
}

std::vector<std::vector<std::string>> FindAnagrams(std::vector<std::string> words) { //Ищем слова палиндромы
	std::vector<std::vector<std::string>> anagrams;
	std::vector<std::string> temp_vector;
	std::string temp = "";

	for (int i = 0; i < words.size(); i++) {
		temp = "";
		for (int j = i + 1; j < words.size(); j++){
			if (words[i].size() == words[j].size()) {
				for (int k = 0; k < words[i].size(); k++) {
					temp = words[j][k] + temp;
				}
				if (temp == words[i]) {
					temp_vector.push_back(words[i]);
					temp_vector.push_back(words[j]);
					anagrams.push_back(temp_vector);
					temp_vector.clear();
				}
			}
		}
	}

	return anagrams;
}

void ShowResult(std::vector<std::vector<std::string>> anagrams) { //Функция для вывода результата
	for (int i = 0; i < anagrams.size(); i++) {
		std::cout << anagrams[i][0] << "\t" << anagrams[i][1] << "\n";
	}
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ru");
	std::string sentence;
	std::vector<std::string> words;
	std::vector<std::vector<std::string>> anagrams;

	std::cout << "Введите предложение. Для окончания ввода нажмите ENTER\n";
	getline(std::cin, sentence);
	std::cout << "Текст успешно введён!\n";

	words = SplitText(sentence);
	anagrams = FindAnagrams(words);

	std::cout << "Результат:\n";
	ShowResult(anagrams);
}