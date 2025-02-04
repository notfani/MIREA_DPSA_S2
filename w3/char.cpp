#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

void SplitText(char* sentence, char** words, int& count) { //Формируем массив слов
    int word_index = 0;

    while (*sentence) {
    // Пропускаем пробелы
        while (*sentence && *sentence == ' ') {
            ++sentence;
            }

        if (!*sentence) {
            break;
        }

        // Начало нового слова
        words[word_index] = new char[100]; // Предполагаем максимальную длину слова 100
        int char_index = 0;

        // Чтение слова до пробела или конца строки
        while (*sentence && *sentence != ' ') {
            words[word_index][char_index] = *sentence;
            ++char_index;
            ++sentence;
            }
        words[word_index][char_index] = '\0'; // Нуль-терминатор

        ++count;
        ++word_index;
        }
}

void FindAnagramms(char* words[], char** anagrams, int count) { // Находим анаграммы
    int anagrams_count = 0;

    for (int i = 0; i < count; ++i) {
        if (words[i] == nullptr) {
            continue;
        }
        anagrams[anagrams_count] = new char[strlen(words[i]) + 1];
        strcpy(anagrams[anagrams_count], words[i]);
        ++anagrams_count;

        for (int j = ++i; j < count; ++j) {
            if (words[i] != nullptr && strlen(words[i]) == strlen(words[j])) {
                int freq[256] = { 0 };
                bool isAnagram = true;
                for (int k = 0; words[i][k] != '\0'; ++k) {
                    ++freq[words[i][k]];
                    --freq[words[j][k]];

                }
                for (int b = 0; b < 255; b++)
                    if (freq[b] != 0)
                        isAnagram = false;
                
                if (isAnagram) {
                    anagrams[anagrams_count] = new char[strlen(words[j]) + 1]; // Выделяем память для анаграммы
                    strcpy(anagrams[anagrams_count], words[j]); // Копируем слово
                    ++anagrams_count;
                    words[j] = nullptr; // Помечаем слово как обработанное
                }
            }
        }
    }
}

void ShowResult(char** anagrams, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << anagrams[i] << "\n";
    }
}

int main() {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ru");

	char sentence[255]; //Создаем 256-1 т.к. последний символ \0
    char** anagrams = new char* [255]; // Массив для хранения анаграмм
	char* words[255];
	int word_count = 0;


	std::cout << "Введите предложение. Для окончания ввода нажмите ENTER\n";
	gets_s(sentence);
	std::cout << "Текст успешно введён!\n";

	SplitText(sentence, words, word_count);
    FindAnagramms(words, anagrams, word_count);

    std::cout << "Результат:\n";
    ShowResult(anagrams, word_count);
	
    return 0;
}
