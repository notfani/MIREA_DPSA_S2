#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

void SplitText(char* sentence, char** words, int& count) { //��������� ������ ����
    int word_index = 0;

    while (*sentence) {
    // ���������� �������
        while (*sentence && *sentence == ' ') {
            ++sentence;
            }

        if (!*sentence) {
            break;
        }

        // ������ ������ �����
        words[word_index] = new char[100]; // ������������ ������������ ����� ����� 100
        int char_index = 0;

        // ������ ����� �� ������� ��� ����� ������
        while (*sentence && *sentence != ' ') {
            words[word_index][char_index] = *sentence;
            ++char_index;
            ++sentence;
            }
        words[word_index][char_index] = '\0'; // ����-����������

        ++count;
        ++word_index;
        }
}

void FindAnagramms(char* words[], char** anagrams, int count) { // ������� ���������
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
                    anagrams[anagrams_count] = new char[strlen(words[j]) + 1]; // �������� ������ ��� ���������
                    strcpy(anagrams[anagrams_count], words[j]); // �������� �����
                    ++anagrams_count;
                    words[j] = nullptr; // �������� ����� ��� ������������
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

	char sentence[255]; //������� 256-1 �.�. ��������� ������ \0
    char** anagrams = new char* [255]; // ������ ��� �������� ��������
	char* words[255];
	int word_count = 0;


	std::cout << "������� �����������. ��� ��������� ����� ������� ENTER\n";
	gets_s(sentence);
	std::cout << "����� ������� �����!\n";

	SplitText(sentence, words, word_count);
    FindAnagramms(words, anagrams, word_count);

    std::cout << "���������:\n";
    ShowResult(anagrams, word_count);
	
    return 0;
}
