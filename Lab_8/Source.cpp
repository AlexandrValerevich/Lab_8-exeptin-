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
	~MassIndexException();

	static int countOfException;

};

int SqrtException     ::countOfException = 0;
int MassIndexException::countOfException = 0;


template<typename T>
void PrintArr(vector<T> Mass) {
	for (auto it : Mass) {
		cout << *it << endl;
	}
}

int main() {
	
	setlocale(0, "");

	/*Создаем три динамических массива*/
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
	cout << "Введите количество элементов в массиве B";
	cin >> numOfItemInB;
	if (numOfItemInB < 0) { numOfItemInB = abs(numOfItemInB); }

	for (size_t i = 0; i < numOfItemInB; i++)
	{
		B.push_back(rand()%200 - 100);
	}

	cout << "Введите количество элементов в массиве C";
	cin >> numOfItemInC;
	if (numOfItemInC < 0) { numOfItemInC = abs(numOfItemInC); }

	for (size_t i = 0; i < numOfItemInC; i++)
	{
		if(i >= A.size() || i >= B.size())
	}

	return 0;
}

