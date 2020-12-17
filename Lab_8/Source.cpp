/*Для каждого варианта необходимо создать три массива a, b и с
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
#include <exception>
#include <string>

using namespace std;

class SqrtException : public exception
{
public:
	SqrtException() : exception() {
		countOfException++;
	};
	string massage() const  {
		return "---------> Минус под корнем\n";
	}
	static int countOfException;

};

class MassIndexException: public exception
{
public:
	MassIndexException() : exception() {
		countOfException++;
	};
	string massage() const {
		return "---------> Выход за пределы массива\n";
	}

	static int countOfException;

};

class LogException : public exception
{
public:
	LogException() : exception() {
		countOfException++;
	};
	string massage() const {
		return "---------> Отрицательное или нулевое значение логарифма\n";
	}

	static int countOfException;
};



int SqrtException     ::countOfException = 0;
int LogException      ::countOfException = 0;
int MassIndexException::countOfException = 0;


template<typename T>
void PrintArr(vector<T> Mass) {
	cout << "=======================================================" << endl;
	for (auto it = Mass.begin(); it != Mass.end(); ++it) {
		cout << *it << endl;
	}
	cout << "=======================================================" << endl;
}

int main() {
	setlocale(0, "");

	vector<double> A;
	vector<double> B;
	vector<double> C;

	for (double i = -2; i <= 2; i+=0.2)
	{
		try
		{
			if (1 - pow(i, 2) < 0) {
				throw SqrtException();
			}
			A.push_back(sqrt(1 - pow(i, 2)));
		}
		catch (const SqrtException& ex)
		{
			cout << ex.massage();
			A.push_back(0);
		}
			
	}

	int numOfItemInB;
	int numOfItemInC;
	cout << "Введите количество элементов в массиве B ";
	cin >> numOfItemInB;
	if (numOfItemInB < 0) { numOfItemInB = abs(numOfItemInB); }

	for (int i = 0; i < numOfItemInB; i++)
	{
		B.push_back(rand()%200 - 100);
	}

	cout << "Введите количество элементов в массиве C ";
	cin >> numOfItemInC;
	if (numOfItemInC < 0) { numOfItemInC = abs(numOfItemInC); }


	for (int i = 0; i < numOfItemInC; i++)
	{
		try
		{
			if (i >= (int)A.size() || i >= (int)B.size()) throw MassIndexException();
			if (B.at(i) >= A.at(i))                       throw LogException();

			C.push_back(log10(A.at(i) - B.at(i)));
		}
		catch (const MassIndexException& ex)
		{
			cout << ex.massage();
			C.push_back(0);
		}
		catch (const LogException& ex)
		{
			cout << ex.massage();
			C.push_back(0);
		}
	}
	

	
	cout << "Массив A" << endl;
	PrintArr(A);
	cout << "Массив B" << endl;
	PrintArr(B);
	cout << "Массив C" << endl;
	PrintArr(C);

	return 0;
}

