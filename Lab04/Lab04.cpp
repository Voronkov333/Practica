#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int cnt = 0, ipos = 0, i = 0, j = 0, temp, y;
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt");
	if (!fin) { cout << " Файл input.txt не найден " << endl; return 1; }
	int R, C;
	fin >> R >> C;
	double **a = new double *[R];
	for (i = 0; i < R; i++) a[i] = new double[C];
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++) fin >> a[i][j];

	cout << "Исходная матрица: " << endl;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			cout << setw(5) << a[i][j] << "   ";
		cout << endl;
	}

	for (i = 0; i < R; i++)
	{
		temp = 0;
		for (j = 0; j < C; j++)
			if (a[i][j] != 0)
				temp = 1;
		if (temp == 0)
		{
			for (y = i; y < R - 1; y++)
				for (j = 0; j < C; j++)
					a[y][j] = a[y + 1][j]; 	R--;
		}
	}
	for (i = 0; i < C; i++)
	{
		temp = 0;
		for (j = 0; j < R; j++)
			if (a[j][i] != 0)
				temp = 1;
		if (temp == 0)
		{
			for (y = i; y < C - 1; y++)
				for (j = 0; j < R; j++)
					a[j][y] = a[j][y + 1];  C--;
		}
	}
	cout << endl;
	cout << "Результат удаления строк/столбцов:" << endl;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			cout << setw(5) << a[i][j] << "  ";
		cout << endl;
	}
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			if (a[i][j] > 0)
			{
				ipos = i;
				cnt++;
				break;
			}
		if (1 == cnt)
		{
			cout << endl << " Номер строки, которая содержит первый положительный элемент: " << ipos + 1 << endl;
			break;
		}
	}
	if (0 == cnt)
		cout << " Таких строк нет!" << endl;
	system("pause");
}