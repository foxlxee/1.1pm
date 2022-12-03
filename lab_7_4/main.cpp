/*
Лабораторная работа 7. Вариант 4.
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть еще один элемент, равный ее минимальному элементу, и не менее 2-х элементов, абсолютные величины которых - простые числа, упорядочить строки матрицы по невозрастанию произведений элементов.
*/

#include <iostream>
#include "functions.hpp"

#define LINE_LENGTH 50

int main() {
	int A[N][N];

	mo::readMatrix(A);
	mo::printLine(LINE_LENGTH);
	mo::printMatrix(A);

	if (mo::checkValues(A) && mo::containsPrimeNumbers(A)) {
		mo::sort(A);

		mo::printLine(LINE_LENGTH);
		mo::printMatrix(A);
	}
}