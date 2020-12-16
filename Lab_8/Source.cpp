﻿/*Для каждого варианта необходимо создать три массива a, b и с
размерами соответственно n1, n2 и n3 (n1n2n3). В массив а занести значения
функции f(x) согласно варианту (при возникновении исключения заносить
нули). Массив b заполнить случайными числами (среди них должны быть и
отрицательные числа и нули). Массив с формируется согласно варианту.
Предусмотреть и обработать возникающие при этом исключительные
ситуации (деление на ноль, корень из отрицательного числа, арифметическое
переполнение, выход за пределы диапазона индексов массива и т.п.).
Варианты заданий приведены в таблице.*/

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <locale.h>

using namespace std;

void main() {
	
	setlocale(0, "");

	/*Создаем три динамических массива*/
	vector<double> A;
	vector<double> B;
	vector<double> C;

	for (double i = -2; i <= 2; i+=0.2)
	{
		try
		{
			A.push_back(sqrt(1 - pow(i, 2)));
		}
		catch (const exception& ex)
		{
			const char* m = ex.what();
			while (m++) {
				cout << *m;
			}
		}
			
	}
	

	return;
}

