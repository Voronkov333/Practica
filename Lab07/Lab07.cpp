#include <fstream>
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <math.h>
#include <iomanip>


using namespace std;

double fz1(int a) {
	double z1, P = 3.14159265;
	z1 = (sin(4 * a) / (1 + cos(4 * a)))*(cos(2 * a) / (1 + cos(2 * a)));
	return z1;
}

double fz2(int a) {
	double z2, P = 3.14159265;
	z2 = 1 / tan(1.5*P - a);
	return z2;
}

void itog01(double z1, double z2) {
	cout << endl << "z1: " << z1 << endl << "z2: " << z2 << endl;
}

void lab02(double xn, double xk, double dx, double eps) {
	int n = 0;
	const int MaxIter = 500; // максимально допустимое количество итераций
	bool done = true; // признак достижения точности
	double x = 1, ch = x, y = ch; // первый член ряда и начальное значение суммы
	cout << "|\t" << "x" << "\t|\t" << "y" << "\t\t|\t" << "n" << "\t|" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (x = xn; x < xk; x += dx) {
		ch = x, y = ch;
		for (n = 0; fabs(ch) > eps; n++) {
			ch *= (-2 * x * (n * n + 2 * n + 2)) / (n * n + 4 * n + 5); // очередной член ряда
			y += ch; // добавление члена ряда к сумме
			if (n > MaxIter) {
				cout << "|\t" << x << "\t|\t" << setw(8) << "Ряд расходится!" << "\t|\t" << n << "\t|" << endl;
				done = false; break;
			}

		}
		if (done)cout << "|\t" << x << "\t|\t" << setw(8) << y << "\t|\t" << n << "\t|" << endl;
	}
}

int vvod_m(double a[], int n) {
	cout << endl << " Введите" << n << "элементов массива:\n ";
	for (int i = 0; i < n; i++) cin >> a[i];
	return *a;
}

double summ(double a[], int n) {
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

int indMax(double a[], int n) {
	int i = 0, imax = 0;
	for (i = 0; i < n; i++) {//Максимальный по модулю
		if (sqrt(a[i] * a[i]) > sqrt(a[imax] * a[imax])) imax = i;
	}
	return imax;
}

int sort(double a[], int n) {
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
	return *a;
}

void itog03(double sum, int imax, double a[], int n) {
	setlocale(LC_ALL, "Russian");
	cout << "Упорядоченный массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << "Сумма элементов, находящихся после первого положительного элемента: " << sum << endl;
	cout << "Номер максимального по модулю элемента: " << imax + 1 << endl;
}

void numbR(double **a, int R, int C) {
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

void vivod_m(double **a, int R, int C) {
	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << setw(5) << a[i][j] << "   ";
		cout << endl;
	}
}

void Sort2(double **a, int &R, int &C) {
	int temp = 0, i = 0, j = 0, y = 0;
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
}

void Itog04(double **a, int R, int C) {
	cout << "Результат удаления строк/столбцов:" << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << setw(5) << a[i][j] << "  ";
		cout << endl;
	}
}

void Lines(char *buf) {
	long i = 0;
	while (buf[i] != '\0') {
		if (buf[i] == '-' && buf[i - 1] == ' ') {
			while (buf[i - 1] != '.' && buf[i] != '\0') {
				cout << buf[i]; i++;
			}
			cout << endl;
		}
		i++;
	}
}

const int l_fam = 20, l_name = 20, l_namber = 12;

struct NOTE {
	char fam[l_fam];
	char name[l_name];
	char namber_t[l_namber];
	int dt[3];
};

void zapoln_struct(NOTE *S2, int n) {

	for (int j = 0; j < n; j++) {
		cout << " Введите данные человека № " << j + 1 << endl;
		cout << " Введите фамилию: ";
		cin.getline(S2[j].fam, l_fam + 1);
		OemToChar(S2[j].fam, S2[j].fam);
		cin.getline(S2[j].fam, l_fam + 1);
		OemToChar(S2[j].fam, S2[j].fam);

		cout << " Введите имя: ";
		cin.getline(S2[j].name, l_name + 1);
		OemToChar(S2[j].name, S2[j].name);

		cout << " Введите номер телефона: ";
		cin.getline(S2[j].namber_t, l_namber + 1);
		OemToChar(S2[j].namber_t, S2[j].namber_t);

		cout << "Введите дату рождения:" << endl;
		cout << "Введите число: "; cin >> S2[j].dt[0];
		cout << "Введите месяц: "; cin >> S2[j].dt[1];
		cout << "Введите год: "; cin >> S2[j].dt[2];

	}
}

void sort_struct(NOTE *S2, NOTE S1, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (S2[j].dt[2] > S2[j + 1].dt[2]) {
				S1 = S2[j];
				S2[j] = S2[j + 1];
				S2[j + 1] = S1;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (S2[j].dt[1] > S2[j + 1].dt[1] && S2[j].dt[2] == S2[j + 1].dt[2]) {
				S1 = S2[j];
				S2[j] = S2[j + 1];
				S2[j + 1] = S1;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (S2[j].dt[0] > S2[j + 1].dt[0] && S2[j].dt[2] == S2[j + 1].dt[2] && S2[j].dt[1] == S2[j + 1].dt[1]) {
				S1 = S2[j];
				S2[j] = S2[j + 1];
				S2[j + 1] = S1;
			}
		}
	}
	cout << "\nДанные, упорядоченные по дате рождения: " << endl;
	for (int j = 0; j < n; j++) {
		cout << "Фамилия: " << S2[j].fam << endl << "Имя: " << S2[j].name << endl << "Номер телефона: " << S2[j].namber_t << endl << "Дата рождения: ";
		for (int i = 0; i < 3; i++)cout << S2[j].dt[i] << ".";
		cout << endl;
	}
}

void Poisk(NOTE *S2, int n) {
	char numb[l_namber];
	cout << "\nВведите номер для поиска: ";
	cin.getline(numb, l_namber); OemToChar(numb, numb);
	cin.getline(numb, l_namber); OemToChar(numb, numb);
	bool cnt;
	for (int j = 0; j < n; j++) {
		cnt = false;
		if (strstr(numb, S2[j].namber_t)) { cnt = true; }
		if (cnt == true) {
			cout << endl << S2[j].fam << "\t" << S2[j].name << "\t";
			for (int i = 0; i < 3; i++)cout << S2[j].dt[i] << "."; break;
		}
	}
	if (cnt == false)cout << "Такого человека в базе нет!" << endl;
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Lab01
	cout << "--------------------------------------Lab01-------------------------------------" << endl;
	{int a;
	double z1, z2;
	cout << "Введите а: ";
	cin >> a;
	z1 = fz1(a);
	z2 = fz2(a);
	itog01(z1, z2); }

	//Lab02
	cout << "--------------------------------------Lab02-------------------------------------" << endl;
	double eps = 0, xn, xk, dx;
	{cout << "\nВведите точность:\n";
	cin >> eps;

	cout << "\nВведите Хнач, Хкон и dX:\n";
	cin >> xn >> xk >> dx;
	lab02(xn, xk, dx, eps); }

	//Lab03
	cout << "--------------------------------------Lab03-------------------------------------" << endl;
	{
		int n = 0, imax = 0;
		double sum = 0;
		setlocale(LC_ALL, "Russian");
		cout << endl << " Введите количество элементов:\n"; cin >> n;
		double *a = new double[n];

		vvod_m(a, n);
		sort(a, n);
		imax = indMax(a, n);
		sum = summ(a, n);
		itog03(sum, imax, a, n);
	}

	//Lab04
	cout << "--------------------------------------Lab04-------------------------------------" << endl;
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
		vivod_m(a, R, C);
		Sort2(a, R, C);
		Itog04(a, R, C);
		numbR(a, R, C);
	}
	//Lab05
	cout << "--------------------------------------Lab05-------------------------------------" << endl;
	{
		setlocale(LC_ALL, "Rus");
		ifstream fin("text.txt", ios::in);
		if (!fin) {
			cout << " Ошибка " << endl; return 1;
		}
		fin.seekg(0, ios::end);
		long len = fin.tellg();
		char*buf = new char[len + 1];
		fin.seekg(0, ios::beg);
		fin.read(buf, len);
		Lines(buf);
		fin.close();
		cout << endl;
	}
	//Lab06
	cout << "--------------------------------------Lab06-------------------------------------" << endl;
	{
		int n = 5;
		cout << "Введите колличество студентов: " << endl;
		cin >> n;
		NOTE *S2 = new NOTE[n];
		NOTE S1 = S2[0];

		zapoln_struct(S2, n);

		cout << "-----------------------------------РЕЗУЛЬТАТЫ-----------------------------------" << endl;
		sort_struct(S2, S1, n);
		Poisk(S2, n);
		system("pause");
	}
}