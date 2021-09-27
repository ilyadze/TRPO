#include <iostream>
#include <cmath>
#include <conio.h>
#include <iomanip> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	do
	{
		if (cin.good())
		{
			cout << "Введите трехзначное число!" << endl;
			int a;
			cin >> a;
			if (a >= 100 && a <= 999)
			{
				if (a % 2 == 0)
				{
					cout << "Число чётное!" << endl;
				}
				else cout << "Число нечётное!" << endl;
				cout << "Среднее арифметическое равно - " << ((a % 100 - a % 10) / 10 + (a - a % 100) / 100 + a % 10) / 3 << endl;
			}
		}
		else cout << "Введите число!" << endl;
		cout << "Нажмите '1' для продолжения программы!" << endl;
	} while (_getch() == '1');
	return 0;
}


