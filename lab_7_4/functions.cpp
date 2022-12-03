#include <iostream>
#include "functions.hpp"

namespace mo {
	// функция чтения элементов матрицы из консоли
	void readMatrix(int A[N][N]) {
		// считываем значение для каждого элемента
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cin >> A[i][j]; // записываем в матрицу
			}
		}
	}

	// функция вывода элементов матрицы в консоль
	void printMatrix(int A[N][N]) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cout << A[i][j];
				if (j != N - 1) std::cout << ' '; // если последний элемент, не печатаем лишний пробел
			}
			std::cout << std::endl;
		}
	}

	// функция печати линии в консоль
	void printLine(unsigned char length) {
		std::cout << std::endl;
		for (int i = 0; i < length; i++) {
			std::cout << '_';
		}
		std::cout << std::endl;
	}

	// функция, которая возвращает абсолютное значение числа
	int getAbsValue(int value) {
		if (value < 0) {
			return value * -1;
		}

		return value;
	}

	// функция, которая возвращает true: если число является простым
	bool isPrime(int value) {
		if (value < 2) {
			return false;
		}
		for (int d = 2; d <= sqrt(value); d++) {
			if (value % d == 0) {
				return false;
			}
		}
		return true;
	}

	// функция, которая возвращает true: если в матрице есть еще один элемент, равный ее минимальному элементу
	bool checkValues(int A[N][N]) {
		int minValue = INT_MAX;

		bool flag = false; // на случай если ввели значение INT_MAX

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int value = A[i][j];

				if (value < minValue) {
					minValue = value;

					if (!flag) {
						flag = true;
					}

				} else if (flag && value == minValue) {
					return true;
				}
			}
		}

		return false;
	}

	// функция, которая возвращает true: если матрица содержит не менее 2-х элементов, абсолютные величины которых - простые числа
	bool containsPrimeNumbers(int A[N][N]) {
		int amount = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isPrime(getAbsValue(A[i][j]))) {
					amount++;

					if (amount == 2) {
						return true;
					}
				}
			}
		}

		return false;
	}

	// функция, которая возвращает произведение элементов строки
	int product(int A[N][N], int row) {
		int product = A[row][0];
		for (int i = 1; i < N; i++) {
			product = product * A[row][i];
		}
		return product;
	}

	// функция, которая меняет местами значения в переменных
	void swap(int& left, int& right) {
		int temp = left;
		left = right;
		right = temp;
	}

	// функция, которая меняет местами строки матрицы
	void swapRows(int A[N][N], int leftIndex, int rightIndex) {
		for (int i = 0; i < N; i++) {
			swap(A[leftIndex][i], A[rightIndex][i]);
		}
	}

	// функция, которая упорядочивает строки матрицы по невозрастанию произведений элементов
	void sort(int A[N][N]) {
		// кешируем значения произведений элементов всех строк
		int products[N];
		for (int i = 0; i < N; i++) {
			products[i] = product(A, i);
		}

		// сортируем матрицу
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (products[i] < products[j]) {
					swapRows(A, i, j);
				}
			}
		}
	}
}