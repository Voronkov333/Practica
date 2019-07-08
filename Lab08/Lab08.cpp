#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T> void vvod_m(T a[], int n) {
	cout << endl << " Введите" << n << "элементов массива:\n ";
	for (int i = 0; i < n; i++) cin >> a[i];
}

template <class T> T summ(T a[], int n) {
	int pol = 0, i = 0;
	double sum = 0;
	for (i = 0; i < n; i++) {//Первый положительный
		if (a[i] > 0) { pol = a[i]; break; }
	}
	if (pol != 0) {
		for (++i; i < n; i++) {
			sum += a[i];
		}
	}
	else { cout << endl << "Положительных элементов нет!" << endl; }
	return sum;
}

template <class T> int indMax(T a[], int n) {
	int i = 0, imax = 0;
	for (i = 0; i < n; i++) {//Максимальный по модулю
		if (sqrt(a[i] * a[i]) > sqrt(a[imax] * a[imax])) imax = i;
	}
	return imax;
}

template <class T> void sort(T a[], int n) {
	int m = 0, b1 = 0, b2 = 0;
	double zam;
	cout << "Введите интервал [a;b]:" << endl; cin >> b1 >> b2;//Сортировка по интервалу
	for (int i = 0; i < n; i++) {
		if (a[i] >= b1 && (int)a[i] <= b2) {
			zam = a[m];
			a[m] = a[i];
			a[i] = zam;
			m++;
		}
	}
}

template <class T> void itog04(T sum, int imax, T a[], int n) {
	setlocale(LC_ALL, "Russian");
	cout << "Упорядоченный массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << "Сумма элементов, находящихся после первого положительного элемента: " << sum << endl;
	cout << "Номер максимального по модулю элемента: " << imax + 1 << endl;
}

template <class T> void numbR(T **a, int R, int C) {
	int cnt = 0, ipos = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
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
}

template <class T> void vivod_m(T **a, int R, int C) {
	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << setw(5) << a[i][j] << "   ";
		cout << endl;
	}
}

template <class T> void Sort2(T **a, int &R, int &C) {
	int temp = 0;
	for (int i = 0; i < R; i++)
	{
		temp = 0;
		for (int j = 0; j < C; j++)
			if (a[i][j] != 0)
				temp = 1;
		if (temp == 0)
		{
			for (int y = i; y < R - 1; y++)
				for (int j = 0; j < C; j++)
					a[y][j] = a[y + 1][j]; 	R--;
		}
	}
	for (int i = 0; i < C; i++)
	{
		temp = 0;
		for (int j = 0; j < R; j++)
			if (a[j][i] != 0)
				temp = 1;
		if (temp == 0)
		{
			for (int y = i; y < C - 1; y++)
				for (int j = 0; j < R; j++)
					a[j][y] = a[j][y + 1];  C--;
		}
	}
	cout << endl;
}

template <class T> void Itog05(T **a, int R, int C) {
	cout << "Результат удаления строк/столбцов:" << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << setw(5) << a[i][j] << "  ";
		cout << endl;
	}
}

int main() {

	cout << "--------------------------------------Lab03-------------------------------------" << endl;
	{
		int n = 0, imax = 0;
		float sum = 0;
		setlocale(LC_ALL, "Russian");
		cout << endl << " Введите количество элементов:\n"; cin >> n;
		float *a = new float[n];

		vvod_m(a, n);
		sort(a, n);
		sum = summ(a, n);
		imax = indMax(a, n);
		itog04(sum, imax, a, n);
	}

	//Lab05
	cout << "--------------------------------------Lab04-------------------------------------" << endl;
	{
		int cnt = 0, ipos = 0, i = 0, j = 0, temp, y;
		setlocale(LC_ALL, "Russian");
		ifstream fin("input.txt");
		if (!fin) { cout << " Файл input.txt не найден " << endl; return 1; }
		int R, C;
		fin >> R >> C;
		float **a = new float *[R];
		for (i = 0; i < R; i++) a[i] = new float[C];
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++) fin >> a[i][j];
		vivod_m(a, R, C);
		Sort2(a, R, C);
		Itog05(a, R, C);
		numbR(a, R, C);
	}
	system("pause");
}