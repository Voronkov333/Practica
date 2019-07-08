#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int i = 0, n = 0, imax = 0, b1 = 0, b2 = 0, m = 0;
	double pol = 0, sum = 0, zam = 0;
	setlocale(LC_ALL, "Russian");
	cout << endl << " Введите количество элементов:\n"; cin >> n;
	double *a = new double[n];

	cout << endl << " Введите элементы массива:\n ";
	for (i = 0; i < n; i++) cin >> a[i];



	cout << "Введите интервал [a;b]:" << endl; cin >> b1 >> b2;//Сортировка по интервалу
	for (i = 0; i < n; i++) {
		if (a[i] >= b1 && (int)a[i] <= b2) {
			zam = a[m];
			a[m] = a[i];
			a[i] = zam;
			m++;
		}
	}
	cout << "Преобразованный массив: " << endl;
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	for (i = 0; i < n; i++) {//Максимальный по модулю
		if (sqrt(a[i] * a[i]) > sqrt(a[imax] * a[imax])) imax = i;
	}
	for (i = 0; i < n; i++) {//Первый положительный
		if (a[i] > 0) { pol = a[i]; break; }
	}
	if (pol != 0) {
		for (++i; i < n; i++) {
			sum += a[i];
		}
	}
	else { cout << endl << "Положительных элементов нет!" << endl; }
	cout << endl << "Сумма элементов, находящихся после первого положительного элемента: " << sum << endl;
	cout << "Номер максимального по модулю элемента: " << imax + 1 << endl;
	delete[] a;
	system("pause");
}