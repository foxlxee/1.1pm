/*
Задача учебной практики 3. Вариант 4.
В текстовом файле input.txt записан русский текст.
Найти в тексте слова, содержащие две одинаковые буквы подряд, записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
Полученный текст записать в файл output.txt.
Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.
*/

#include <iostream>
#include <fstream>
#include <vector>

// функция, которая проверяет является ли символ буквой в верхнем регистре
bool isUpper(char c) {
	return c >= 'А' && c <= 'Я';
}

// функция, которая проверяет является ли символ буквой в нижнем регистре
bool isLower(char c) {
	return c >= 'а' && c <= 'я';
}

// функция, которая переводит букву в верхний регистр
char toUpper(char c) {
	if (isLower(c)) {
		return c - 32;
	}
	return c;
}

// функция, которая переводит букву в нижний регистр
char toLower(char c) {
	if (isUpper(c)) {
		return c + 32;
	}
	return c;
}

// функция, которая проверяет является ли символ буквой
bool isLetter(char c) {
	return isUpper(c) || isLower(c);
}

// функция, которая записывает слово
void write(std::vector<char>& word, std::vector<char>& foundLetters, std::ofstream& outputFileStream) {
	if (word.size() > 0) {
		// записываем слово
		for (size_t i = 0; i < word.size() - 1; i++) {
			char left = toLower(word[i]);
			char right = toLower(word[i + 1]);

			if (left == right) {
				word[i] = toUpper(left);
				word[i + 1] = toUpper(right);

				if (std::find(
					foundLetters.begin(),
					foundLetters.end(),
					left) == foundLetters.end()) {
					foundLetters.push_back(left);
				}
			}
		}

		for (size_t i = 0; i < word.size(); i++) {
			std::cout << word[i];
			outputFileStream << word[i];
		}
		word.clear();

		// записываем в скобках после слова все найденные буквы
		if (foundLetters.size() > 0) {
			std::cout << '(';
			outputFileStream << '(';

			for (size_t i = 0; i < foundLetters.size(); i++) {
				std::cout << foundLetters[i];
				outputFileStream << foundLetters[i];
			}

			std::cout << ')';
			outputFileStream << ')';

			foundLetters.clear();
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	// входной файловый поток
	std::ifstream inputFileStream("input.txt");

	if (!inputFileStream.good()) {
		std::cout << "input.txt не удалось открыть";
		std::cin.get();
		return -1;
	}

	// выходной файловый поток
	std::ofstream outputFileStream("output.txt", std::ios::trunc);

	// считанный символ
	char c;

	// слово, которое проверяется
	std::vector<char> word;

	// найденные идущие подряд буквы в слове
	std::vector<char> foundLetters;

	while (!inputFileStream.eof()) {
		inputFileStream.get(c);

		if (isLetter(c)) {
			word.push_back(c);
		} else {
			// записываем слово и найденные буквы
			write(word, foundLetters, outputFileStream);

			// записываем символ
			std::cout << c;
			outputFileStream << c;
		}

		inputFileStream.peek();
	}

	// записываем последнее слово и найденные буквы
	write(word, foundLetters, outputFileStream);
}