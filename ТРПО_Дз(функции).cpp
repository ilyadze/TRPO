#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <conio.h>
#include <time.h>

using namespace std;

string changeNumToString(int integer);
string changeNumToString(double number);
string changeNumToString(int integer, int n);
int maxAmount(int* array, int size, int* max);
int maxAmount(string array_num, int size, char* max);



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	cout << "Задание №1-2" << endl;
	do
	{
		cout << "Выберите тип числа " << endl
			<< "1.Целое число" << endl
			<< "2.Дробное число" << endl
			<< "3.Целое число с выводом задонного количества элементов" << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "Введите число ";
			int num_int;
			cin >> num_int;
			cout << "Число " << changeNumToString(num_int) << endl;
			break;
		}
		case '2':
		{
			cout << "Введите дробное число ";
			double num_double;
			cin >> num_double;
			cout << "Число " << changeNumToString(num_double) << endl;
			break;
		}
		case '3':
		{
			cout << "Введите целое число ";
			int num_int_2;
			cin >> num_int_2;
			cout << "Введите количество выводимых элементов ";
			int n;
			cin >> n;
			cout << changeNumToString(num_int_2, n) << endl;
			break;
		}
		default:
		{
			cout << "Данный вариант отсутствует" << endl;
		}
		}
		cout << "Нажмите 1 для продолжения работы с этим заданием " << endl;
	} while (_getch() == '1');
	cout << "Задание №3" << endl;
	do
	{
		cout << "Введите размер массива " << endl;
		int size;
		cin >> size;
		int* array_num;
		array_num = new int[size];
		cout << "Выберите вариант заполнения массива " << endl
			<< "1.Заполнение самостоятельно " << endl
			<< "2. Заполнение рандомно" << endl;
		switch (_getch())
		{
		case '1':
		{
			for (int i = 0;i < size;i++)
			{
				cin >> array_num[i];
			}
			break;
		}
		case '2':
		{
			for (int i = 0;i < size;i++)
			{
				array_num[i] = rand() % 21 - 10;
			}
			break;
		}
		default:
		{
			cout << "Данный вариант заполнения отсутствует " << endl;
		}
		}
		cout << "Массив" << endl;
		for (int i = 0;i < size;i++)
		{
			cout << array_num[i] << "\t";
		}
		cout << endl;
		int* max, max_element;
		max = &max_element;
		cout << "Число " << *max << " встречается " << maxAmount(array_num, size, max);
		if (maxAmount(array_num, size, max) < 5 && maxAmount(array_num, size, max) > 1)
		{
			cout << " раза" << endl;
		}
		else
		{
			cout << " раз" << endl;
		}
		cout << "Нажмите 1 для продолжения работы с этим заданием " << endl;
	} while (_getch() == '1');
	cout << "№3.Дополнительное задание " << endl
		<< "Введите массив символов" << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	string array_symbols;
	char max_symbols, * max;
	max = &max_symbols;
	getline(cin, array_symbols);
	cout << "Элемент " << *max << " встречается " << maxAmount(array_symbols, int(array_symbols.length()), max);
	if (maxAmount(array_symbols, int(array_symbols.length()), max) < 5 && maxAmount(array_symbols, int(array_symbols.length()), max) > 1)
	{
		cout << " раза" << endl;
	}
	else
	{
		cout << " раз" << endl;
	}
}



string changeNumToString(int integer)
{
	string str = "";
	while (integer > 0)
	{
		str += (char)(integer % 10 + 48);
		integer /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}
string changeNumToString(double number)
{
	string str;
	double  whole_part;
	double b;
	double number_2 = number;
	modf(number, &b);
	number_2 -= b;
	str += changeNumToString(int(b));
	int length = 0;
	while (modf(number, &whole_part) != 0)
	{
		number *= 10;
		length++;
	}
	str += '.';
	for (int i = 0;i < length;i++)
	{
		number_2 *= 10;
		str += char(int(number_2) % 10 + 48);
		number_2 -= int(number_2);
	}
	return str;
}
string changeNumToString(int integer, int n)
{
	int i = 0;
	string str = "";
	int length = integer;
	while (length > 0)
	{
		length /= 10;
		i++;
	}
	while (integer > 0)
	{
		if (i <= n)
		{
			str += (char)(integer % 10 + 48);
		}
		integer /= 10;
		i--;
	}
	reverse(str.begin(), str.end());
	return str;
}


int maxAmount(int* array_num, int size, int* max)
{
	*max = array_num[0];
	int max_amount = 0, amount;
	for (int i = 0;i < size;i++)
	{
		amount = 1;
		for (int j = (i + 1);j < size + 1;j++)
		{
			if (array_num[i] == array_num[j])
			{
				amount++;
				i++;
			}
			else
			{
				if (max_amount <= amount)
				{
					max_amount = amount;
					*max = array_num[i];
				}
				else
				{
					break;
				}
			}
		}
	}
	return max_amount;
}
int maxAmount(string array_num, int size, char* max)
{
	int max_amount = 0, amount;
	for (int i = 0;i < size;i++)
	{
		amount = 1;
		for (int j = i + 1;j < size + 1;j++)
		{
			if (array_num[i] == array_num[j])
			{
				amount++;
				i++;
			}
			else
			{
				if (max_amount < amount)
				{
					max_amount = amount;
					*max = array_num[i];
				}
				else
				{
					break;
				}
			}
		}
	}
	return max_amount;
}