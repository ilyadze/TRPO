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
			int month;
			cout << "Введите номер месяца" << endl;
			cin >> month;
			switch (month)
			{
			case(1):cout << "Зима,Январь" << endl;break;
			case(2):cout << "Зима,Февраль" << endl;break;
			case(3):cout << "Весна,Март" << endl;break;
			case(4):cout << "Весна,Апрель" << endl;break;
			case(5):cout << "Весна,Май" << endl;break;
			case(6):cout << "Лето,Июнь" << endl;break;
			case(7):cout << "Лето,Июль" << endl;break;
			case(8):cout << "Лето,Август" << endl;break;
			case(9):cout << "Осень,Сентябрь" << endl;break;
			case(10):cout << "Осень,Октябрь" << endl;break;
			case(11):cout << "Осень,Ноябрь" << endl;break;
			case(12):cout << "Зима,Декабря" << endl;break;
			default:cout << "Ошибка" << endl;break;
			}

		}
		else cout << "Введите число!" << endl;
		cout << "Нажмите '1' для продолжения программы!" << endl;
	} while (_getch() == '1');
	return 0;
}
