#include <iostream>
#include <conio.h>


using namespace std;

unsigned short lfsr = 0xACE1u;
unsigned bit;


unsigned random(int size_1, int size_2)
{
		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
		return (lfsr = (lfsr >> 1) | (bit << 15)) % (size_1 - size_2 + 1) + size_1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	do
	{
		int number;
		cout << "Введите номер задания" << endl;
		cin >> number;
		switch (number)
		{
		case 1:
		{
			int area, perimetr, a, b, i, j;
			cout << "Введите размеры прямоугольника" << endl;
			cin >> a >> b;
			area = a * b;
			perimetr = (a + b) * 2;
			cout << "Площадь равна" << area << endl;
			cout << "Периметр равен" << perimetr << endl;
			for (i = 1;i <= b;i++)
			{
				for (j = 1; j <= a;j++)
				{
					cout << "*";
				}
				cout << endl;
			}
			break;
		}
		case 2: 
		{
			int n, factorial = 1, z, k, a_1, a_2, a_3;
			cout << "Введите число" << endl;
			cin >> n;
			for (z = 1;z <= n;z++)
			{
				factorial *= z;
			}
			a_1 = 0;
			a_2 = 1;
			cout <<"Число Фибаначи\n" << a_1 << " " << a_2 << " ";
			for (k = 0;k <=n;k++)
			{
				a_3 = a_1 + a_2;
				a_1 = a_2;
				a_2 = a_3;
				cout << a_3 << " ";

			}
			cout << endl;
			cout << "Факториал равен " << factorial << endl;
			break;
		}
		case 3:
		{
			int number_1, num_1,number_2, num_2 , I, J = 0, R = 0,nod = 1,max,i_3,num_3, H = 0,Num_1,Num_2;
			cout << "Введите числа" << endl;
			do
			{
				cin >> number_1 >> number_2;
				if (number_1 == 0 || number_1 == 1 || number_1 == -1 || number_2 == 0 || number_2 == 1 || number_2 == -1)
					cout << "Числа 0, 1, -1 не относяться не к простым не составным,пожалуйста введите заново" << endl;
			} while (number_1 == 0 || number_1 == 1 || number_1 == -1);
			Num_1 = number_1;
			Num_2 = number_2;
			max = (number_1 > number_2)?number_1:number_2;
			for (I = 2;I <= max;I++)
			{
				num_1 = number_1 % I;
				
				if (num_1 == 0)
				{
					R++;	
				}
				num_2 = number_2 % I;
				if (num_2 == 0)
				{
					J++;
				}
				H = 0;
				if (num_1 == 0 && num_2 == 0)
				{
					for (i_3 = 2;i_3 <= I;i_3++)
					{
						num_3 = I % i_3;
						if (num_3 == 0)
						{
							H++;
						}
					}
						if (H == 1)
						{
							while (number_1 % I == 0 && number_2 % I == 0)
							{
								nod *= I;
								number_1 /= I;
								number_2 /= I;
							}
						}
				}
				
			}
			if (R == 1)cout << "Число " << Num_1 << " простое" << endl;
			else cout << "Число " << Num_1 << " составное" << endl;
			if (J == 1)cout << "Число " << Num_2 << " простое" << endl;
			else cout << "Число " << Num_2 << " составное" << endl;
			cout << "НОД чисел равен " << nod << endl;
			break;

		}
		case 4:
		{
			int X,x[50], i_4;
			cout << "Введите число " << endl;
			cin >> X;
			for(i_4 = 0;X >= 1;i_4++)
			{
				x[i_4] = X%2;
				X = X / 2;
			}
			i_4--;
			for (;i_4 >=0;i_4--)
			{
				cout << x[i_4];
			}
			cout << endl;
			break;
		}
		case 5:
		{
			srand(time(NULL));
			cout << "Введите промежуток" << endl;
			int number_5[100],size_1, size_2,i_5,amount,j_5 ;
			cout << "От" << endl;
			cin >> size_1;
			cout << "До" << endl;
			cin >> size_2;
			cout << "Введите количество чисел" << endl;
			cin >> amount;
			cout << "Числа равны:" << endl;
			for (i_5 = 0;i_5 < amount;i_5++)
			{
				number_5[i_5] = random(size_1, size_2);
				cout << number_5[i_5] <<endl;
			}
			int max;
			for (i_5 = 0;i_5 < amount;i_5++)
			{
				max = (number_5[i_5] > number_5[i_5 + 1]) ? number_5[i_5] : number_5[i_5 + 1];
			}
			cout << "График:" << endl;
			for (i_5 = size_1;i_5 <= size_2;i_5++)
			{
				cout << i_5 <<". ";
				for (j_5 = 0;j_5 < amount;j_5++)
				{
					if (i_5 == number_5[j_5])
					{
						cout << "*";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			break;
		}
		default:
			cout << "Такого задания нет" << endl;
		}
		
		cout << "Введите 1 для продолжения работы программы" << endl;
	} while (_getch() == '1');	
}
