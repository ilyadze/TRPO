#include "validation.h"

int inputNumber(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range))
		{
			return number;
		}
		else
		{
			cout << "Некорректный ввод! Повторите попытку: ";
		}

	}
}

int inputNumber(int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && isNumberRangeCorrect(number, right_range))
		{
			return number;
		}
		else
		{
			cout << "Некорректный ввод! Повторите попытку: ";
		}

	}
}

int inputNumber()
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric())
		{
			return number;
		}
		else
		{
			cout << "Некорректный ввод! Повторите попытку: ";
		}

	}
}

string inputPassword()
{
	string password;
	int i = 0;
	while (true)
	{
		password[i] = _getch();
		cout << "*";
		if (password[i] = 13)
		{
			break;
		}
		i++;
	}
	cout << endl;
	return password;
}

bool isNumberNumeric()
{
	if (cin.get() == '\n')
	{
		return true;
	}
	else
	{
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}

bool isNumberRangeCorrect(int number, int left_range, int right_range)
{
	if ((number > left_range) && (number < right_range))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isNumberRangeCorrect(int number, int right_range)
{
	if (number > NULL && number <= right_range)
	{
		return true;
	}
	else
	{
		return false;
	}

}