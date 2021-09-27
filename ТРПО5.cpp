#include <cmath>
#include <iostream>
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
			int years, year;
			cout << "Введите год" << endl;
			cin >> years;
			year = years % 12;
			switch (year)
			{
			case(1):cout << "Петух" << endl;break;
			case(2):cout << "Собака" << endl;break;
			case(3):cout << "Свинья" << endl;break;
			case(4):cout << "Крыса" << endl;break;
			case(5):cout << "Бык" << endl;break;
			case(6):cout << "Тигр" << endl;break;
			case(7):cout << "Кот(кролик)" << endl;break;
			case(8):cout << "Дракон" << endl;break;
			case(9):cout << "Змея" << endl;break;
			case(10):cout << "Лошадь" << endl;break;
			case(11):cout << "Коза" << endl;break;
			case(0):cout << "Обезьяна" << endl;break;
			}
		}
		else cout << "Введите число!" << endl;
		cout << "Нажмите '1' для продолжения программы!" << endl;
	} while (_getch() == '1');
	return 0;

}
