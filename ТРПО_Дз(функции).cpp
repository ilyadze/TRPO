#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <conio.h>
#include <time.h>

using namespace std;

void changeNumToString(int integer);
void changeNumToString(double number);
void changeNumToString(int integer, int n);
void maxAmount(int* array, int size);
void maxAmount(string array_num, int size);



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
			changeNumToString(num_int);
			break;
		}
		case '2':
		{
			cout << "Введите дробное число ";
			double num_double;
			cin >> num_double;
			changeNumToString(num_double);
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
			changeNumToString(num_int_2, n);
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
		maxAmount(array_num, size);
		cout << "Нажмите 1 для продолжения работы с этим заданием " << endl;
	} while (_getch() == '1');
	cout << "№3.Дополнительное задание "<< endl
		<< "Введите массив символов" << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	string array_symbols;
	getline(cin, array_symbols);
	maxAmount(array_symbols, array_symbols.length());
	
}



void changeNumToString(int integer)
{
	string str = "";
	while (integer > 0)
	{
		str += (char)(integer % 10 + 48);
		integer /= 10;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
}
void changeNumToString(double number)
{ 
	string str;
	ostringstream stream;
	stream << number;
	str = stream.str();
	cout << str << endl;
}
void changeNumToString(int integer, int n)
{
	int i = 0;
	string str = "";
	int length = integer;
	while (length > 0)
	{
		length /= 10;
		i++;
	}
	while (integer > 0 )
	{
		if (i <= n)
		{
			str += (char)(integer % 10 + 48);
		}
		integer /= 10;
		i--;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
}


void maxAmount(int* array_num, int size)
{
	int max_amount = 0, amount, max;
	for (int i = 0;i < size;i++)
	{
		amount = 1;
		for (int j = i + 1;j < size;j++)
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
					max = array_num[i];
				}
				else
				{
					break;
				}
			}


		}
	}
	cout << "Число " << max << " встречается " << max_amount << " раз" << endl;
}
void maxAmount(string array_num, int size)
{
	int max_amount = 0, amount, max = 0;
	for (int i = 0;i < size;i++)
	{
		amount = 1;
		for (int j = i + 1;j < size;j++)
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
					max = array_num[i];
				}
				else
				{
					break;
				}
			}


		}
	}
	cout << "Число " << char(max) << " встречается " << max_amount << " раз" << endl;
}