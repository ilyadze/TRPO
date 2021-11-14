#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <algorithm>

using namespace std;
int i, j;
int lower, upper;
int col, str, num;

void out_matrix(int** mat, int str, int col);

void outArray(int* mat, int col);

double sum_matrix(int** mat, int str, int col);

void fillMatrix(int** mat, int str, int col);

void fillArray(int* mat, int col);

int** createMatrix(int**& mat, int str, int col);

int* createArray(int*& mat, int col);

void deleteMatrix(int str, int** mat);
void deleteArray(int* mat);

void** workMatrix(int** work_mat, int** mat, int str, int col, int** mat_1, int str_1, int col_1);

int removeElements(int* mat, int col);

int medianMatrix(int** mat, int str, int col);

int maxElement(int** mat, int str, int col);

int minElement(int** mat, int str, int col);

int comp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}



int main()
{
	do
	{
		setlocale(LC_ALL, "ru");
		srand(time(NULL));

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
			cout << "Задайте размеры матрицы" << endl;
			cin >> str >> col;
			int** mat = createMatrix(mat, str, col);
			fillMatrix(mat, str, col);
			out_matrix(mat, str, col);

			deleteMatrix(str, mat);

			break;
		}
		case '2':
		{
			cout << "Задайте размеры матрицы" << endl;
			cin >> str >> col;
			int** mat = createMatrix(mat, str, col);
			fillMatrix(mat, str, col);
			out_matrix(mat, str, col);

			cout << "Сумма равна " << sum_matrix(mat, str, col) << endl;
			cout << "Среднее арифметическое равно " << sum_matrix(mat, str, col) / (col * str) << endl;

			deleteMatrix(str, mat);

			break;
		}
		case '3':
		{
			cout << "Задайте размеры матрицы" << endl;
			cin >> str >> col;
			int** mat = createMatrix(mat, str, col);
			fillMatrix(mat, str, col);

			cout << "Введите размеры второй матрицы (количество столбцов первой матрицы должно быть равно количеству строк первой матрицы )" << endl;
			int str_1, col_1;
			do
			{
				cin >> str_1 >> col_1;
				if (col_1 != str)
				{
					cout << "Количество столбцов первой матрицы не равно количеству строк первой матрицы" << endl;
				}
			} while (col != str_1);
			int** mat_1 = createMatrix(mat_1, str_1, col_1);
			fillMatrix(mat_1, str_1, col_1);

			cout << "Первая ";
			out_matrix(mat, str, col);

			cout << "Вторая  ";
			out_matrix(mat_1, str_1, col_1);

			int** work_mat = createMatrix(work_mat, str, col_1);
			workMatrix(work_mat, mat, str, col, mat_1, str_1, col_1);
			cout << "Произведение  ";
			out_matrix(work_mat, str, col_1);

			deleteMatrix(str, mat_1);
			deleteMatrix(str, work_mat);
			deleteMatrix(str, mat);

			break;
		}
		case '4':
		{
			cout << "Введите размер массива" << endl;
			cin >> col;
			int* mat = createArray(mat, col);
			fillArray(mat, col);
			outArray(mat, col);

			col = removeElements(mat, col);
			outArray(mat, col);

			cout << "Медиана массива равна " << mat[col / 2] << endl;

			deleteArray(mat);

			break;
		}
		case '5':
		{
			cout << "Задайте размеры матрицы" << endl;
			cin >> str >> col;
			int** mat = createMatrix(mat, str, col);
			fillMatrix(mat, str, col);

			cout << "До сортировки" << endl;
			out_matrix(mat, str, col);

			int median = medianMatrix(mat, str, col);

			cout << "После сортировки" << endl;
			out_matrix(mat, str, col);

			cout << "Максимальный элемент матрицы равен " << maxElement(mat, str, col) << endl;
			cout << "Минимальный элемент матрицы равен " << minElement(mat, str, col) << endl;
			cout << "Медиана матрицы равна " << median << endl;

			deleteMatrix(str, mat);

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


void fillMatrix(int** mat, int str, int col)
{
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}

}

void fillArray(int* mat, int col)
{
	for (i = 0;i < col;i++)
	{
		mat[i] = rand() % (upper - lower + 1) + lower;
	}
}


int** createMatrix(int**& mat, int str, int col)
{
	mat = new int* [str];
	for (i = 0;i < str;i++)
	{
		mat[i] = new int[col];
	}
	return mat;
}

int* createArray(int*& mat, int col)
{
	mat = new int[col];
	return mat;
}


void deleteMatrix(int str, int** mat)
{
	for (i = 0; i < str; i++)
	{
		delete[]mat[i];
	}
	delete[]mat;
}

void deleteArray(int* mat)
{
	delete[]mat;
}


void out_matrix(int** mat, int str, int col)
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

void outArray(int* mat, int col)
{
	cout << "Массив " << endl;
	for (i = 0;i < col;i++)
	{
		cout << mat[i] << "\t";
	}
	cout << endl;
}



double sum_matrix(int** mat, int str, int col)
{
	double sum = 0;
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			sum += mat[i][j];
		}
	}
	return sum;
}


void** workMatrix(int** work_mat, int** mat, int str, int col, int** mat_1, int str_1, int col_1)
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
	return 0;
}

int removeElements(int* mat, int col)
{
	qsort(mat, col, sizeof(int), comp);
	for (i = 0;i < col - 1;++i)
	{
		for (j = i + 1; j < col; ++j)
		{
			if (mat[i] == mat[j])
			{
				for (int k = j; k < col - 1;k++)
				{
					mat[k] = mat[k + 1];
				}
				col--;
				j--;
			}
		}
	}
	return col;
}

int medianMatrix(int** mat, int str, int col)
{
	int k = 0;
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
	qsort(mat_5, col * str, sizeof(int), comp);
	k = 0;
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			mat[i][j] = mat_5[k];
			k++;
		}
	}
	int median = mat_5[col * str / 2];
	deleteArray(mat_5);
	return median;
}

int maxElement(int** mat, int str, int col)
{
	int max = mat[0][0];
	for (i = 0;i < str;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (mat[i][j] > max)
			{
				max = mat[i][j];
			}
		}
	}
	return max;
}

int minElement(int** mat, int str, int col)
{
	int min = mat[0][0];
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
	return min;
}