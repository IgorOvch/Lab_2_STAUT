#include <iostream>
#include <locale.h>

using namespace std;

int LeftNumber(int number);

int CorrectInput(int& value);

void Add(int*& arr, int element, int index, int &length);

void PrintArr(int arr[], int lngth);

int main()
{
	setlocale(LC_ALL,"RUS");
	int length, x;
	cout << "Введите количество чисел\n";
	CorrectInput(length);
	int* Array = new int[length];
	cout << "Введите числа\n";
	for (int i = 0; i < length; i++)
		CorrectInput(Array[i]);
	cout << "Введите число х\n";
	CorrectInput(x);
	for (int i = 0; i < length; i++)
		if (LeftNumber(Array[i]) == 5)
		{
			Add(Array, x, i, length);
			i += 2;
		}
	PrintArr(Array, length);
	delete[] Array;
}

int LeftNumber(int number)
{
	while (number)
	{
		number /= 10;
		if (number / 10 > 9)
			number /= 10;
		else
			return number;
	}
}

int CorrectInput(int& value)
{
	char fail;
	cin >> value;
	while (cin.fail())
	{
		cout << "Данные некорректны\n";
		cin.clear();
		cin >> fail;
		cin >> value;
	}
	return value;
}

void Add(int*& arr, int element, int index, int& length) 
{
	int* newArr = new int[length + 1];
	for (int i = 0; i < index; i++)
		newArr[i] = arr[i];
	newArr[index] = element;
	for (int i = index; i < length; i++)
		newArr[i + 1] = arr[i];
	length++;
	delete[] arr;
	arr = newArr;
}

void PrintArr(int arr[], int lngth)
{
	for (int i = 0; i < lngth; i++)
		cout << arr[i] << "\t";
	cout << endl;
}