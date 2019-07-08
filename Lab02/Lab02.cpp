#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const int MaxIter = 500; // максимально допустимое количество итераций
	double x = 1, eps = 0, xn, xk, dx;
	int n = 0;

	cout << "\n¬ведите точность:\n";
	cin >> eps;

	cout << "\n¬ведите ’нач, ’кон и dX:\n";
	cin >> xn >> xk >> dx;

	bool done = true; // признак достижени€ точности
	double ch = x, y = ch; // первый член р€да и начальное значение суммы

	cout << "|\t" << "x" << "\t|\t" << "y" << "\t\t|\t" << "n" << "\t|" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (x = xn; x < xk; x += dx) {
		ch = x, y = ch;
		for (n = 0; fabs(ch) > eps; n++) {
			ch *= (-2 * x * (n * n + 2 * n + 2)) / (n * n + 4 * n + 5); // очередной член р€да
			y += ch; // добавление члена р€да к сумме
			if (n > MaxIter) {
				cout << "|\t" << x << "\t|\t" << setw(8) << "–€д расходитс€!" << "\t|\t" << n << "\t|" << endl;
				done = false; break;
			}

		}
		if (done)cout << "|\t" << x << "\t|\t" << setw(8) << y << "\t|\t" << n << "\t|" << endl;
	}


	system("pause");
}