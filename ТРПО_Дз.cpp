#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <algorithm>

using namespace std;
int i, j;
int lower, upper;

void out_matrix(int** mat,int str, int col);
void sum_matrix(int str,int col);
void exer_1(int str, int col);
void exer_3(int str, int col);
void exer_4(int str, int col);
void exer_5(int str, int col);


int comp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}



int main()
{
	do
	{
		setlocale(LC_ALL, "ru");
		srand(time(NULL));
		int col = 0, str = 0, num;
		cout << "Введите промежуток чисел " << endl
			<< "От ";
		cin >> lower;
		cout << "До ";
		cin >> upper;
		cout << "Выберите номер задания" << endl;
		switch (_getch())
		{
		case '1':
		{
			exer_1(str, col);
			break;
		}
		case '2':
		{
			sum_matrix(str, col);
			break;
		}
		case '3':
		{
			exer_3(str, col);
			break;
		}
		case '4':
		{
			exer_4(str, col);
			break;
		}
		case '5':
		{
			exer_5(str, col);
			break;
		}
		default:
		{
			cout << "Такого задания нет" << endl;
			break;
		}
		}
		cout << "Нажмите 1 для продолжения работы с программой" << endl;
	} while (_getch() == '1');

}


void exer_1(int str, int col)
{
	int** mat;
	cout << "Задайте размеры матрицы" << endl;
	cin >> str >> col;
	mat = new int* [str];
	for (i = 0;i < str;i++)
	{
		mat[i] = new int[col];
	}

	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	out_matrix(mat, str, col);
	for (i = 0; i < str; i++)
		delete[]mat[i];
	delete[]mat;
}


void out_matrix(int **mat,int str, int col)
{
	cout << "Матрица " << endl;
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			cout << setw(10) << mat[i][j];
		}
		cout << endl;
	}
}



void sum_matrix(int str, int col)
{
	int** mat;
	cout << "Задайте размеры матрицы" << endl;
	cin >> str >> col;
	mat = new int* [str];
	for (i = 0;i < str;i++)
	{
		mat[i] = new int[col];
	}

	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	double sum = 0;
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			sum += mat[i][j];
		}
	}
	out_matrix(mat, str, col);
	cout << "Сумма равна " << sum << endl;
	cout << "Среднее арифметическое равно " << sum/(col*str) << endl;
	for (i = 0; i < str; i++)
		delete[]mat[i];
	delete[]mat;
}


void exer_3(int str, int col)
{
	int** mat;
	cout << "Задайте размеры матрицы" << endl;
	cin >> str >> col;
	mat = new int* [str];
	for (i = 0;i < str;i++)
	{
		mat[i] = new int[col];
	}

	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	int str_1, col_1;
	int** mat_1, ** work_mat;
	do
	{
		cout << "Введите размеры второй матрицы " << endl;
		cin >> str_1 >> col_1;
		mat_1 = new int* [str_1];
		for (i = 0;i < str_1;i++)
		{
			mat_1[i] = new int[col_1];
		}
		work_mat = new int* [str];
		for (i = 0;i < str;i++)
		{
			work_mat[i] = new int[col_1];
		}
		for (i = 0;i < str_1;i++)
		{
			for (j = 0;j < col_1;j++)
			{
				mat_1[i][j] = rand() % (upper - lower + 1) + lower;
			}
		}
		if (col == str_1)
		{
			for (i = 0;i < str;i++)
			{
				for (j = 0;j < col_1;j++)
				{ 
					work_mat[i][j] = 0;
					for (int k = 0;k < col;k++)
					{
						work_mat[i][j] += mat[i][k] * mat_1[k][j];
					}
				}
			}
		}
		else
		{
			cout << "Количество столбоцов первой матрицы не равно количеству столбцов второй матрицы" << endl;
		}
	} while (str_1 != col);
	cout << "Первая ";
	out_matrix(mat, str, col);
	cout << "Вторая  ";
	out_matrix(mat_1, str_1, col_1);
	cout << "Произведение  ";
	out_matrix(work_mat, str, col_1);
	for (i = 0; i < str_1; i++)
		delete[]mat_1[i];
	delete[]mat_1;
	for (i = 0; i < str; i++)
		delete[]work_mat[i];
	delete[]work_mat;
	for (i = 0; i < str; i++)
		delete[]mat[i];
	delete[]mat;
}

void exer_4(int str, int col)
{
	cout << "Введите размер массива" << endl;
	cin >> str;
	int* mat;
	mat = new int[str];
	cout << "Массив " << endl;
	for (i = 0;i < str;i++)
	{
		mat[i] = rand() % (upper - lower + 1) + lower;
		cout << mat[i] << "\t";
	}
	cout << endl;
	qsort(mat, str, sizeof(int), comp1);
	for (i = 0;i < str - 1;++i)
	{
		for (j = i +1; j < str; ++j)
		{
			if (mat[i] == mat[j])
			{
				for (int k = j; k < str - 1;k++)
				{
					mat[k] = mat[k + 1];	
				}
				str--;
				j--;
			}
		}
	}
	cout << "Массив "<< endl;
	for (i = 0;i < str;i++)
	{
		cout << mat[i] << "\t";
	}
	cout << endl;
	cout << "Медиана массива равна " << mat[str/2] << endl;
	cout << endl;
}

void exer_5(int str, int col)
{
	int** mat;
	cout << "Задайте размеры матрицы" << endl;
	cin >> str >> col;
	mat = new int* [str];
	for (i = 0;i < str;i++)
	{
		mat[i] = new int[col];
	}

	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	int max = 0,min = 0,k = 0;
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (mat[i][j] > max)
			{
				max  = mat[i][j];
			}
		}
	}
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (mat[i][j] < min)
			{
				min = mat[i][j];
			}
		}
	}
	cout << "До сортировки" << endl;
	out_matrix(mat, str, col);
	int* mat_5;
	mat_5 = new int[str * col];
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat_5[k] = mat[i][j];
			k++;
		}
	}
	qsort(mat_5, col*str, sizeof(int), comp1);
	k = 0;
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = mat_5[k];
			k++;
		}
	}
	cout << "После сортировки" << endl;
	out_matrix(mat, str, col);
	cout << "Медиана матрицы равна " << mat_5[col*str/2] << endl;
	cout << "Максимальный элемент матрицы равен " << max <<  endl;
	cout << "Минимальный элемент матрицы равен " << min << endl;
	for (i = 0; i < str; i++)
		delete[]mat[i];
	delete[]mat;
}


