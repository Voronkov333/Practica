#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const int MaxIter = 500; // ����������� ���������� ���������� ��������
	double x = 1, eps = 0, xn, xk, dx;
	int n = 0;

	cout << "\n������� ��������:\n";
	cin >> eps;

	cout << "\n������� ����, ���� � dX:\n";
	cin >> xn >> xk >> dx;

	bool done = true; // ������� ���������� ��������
	double ch = x, y = ch; // ������ ���� ���� � ��������� �������� �����

	cout << "|\t" << "x" << "\t|\t" << "y" << "\t\t|\t" << "n" << "\t|" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (x = xn; x < xk; x += dx) {
		ch = x, y = ch;
		for (n = 0; fabs(ch) > eps; n++) {
			ch *= (-2 * x * (n * n + 2 * n + 2)) / (n * n + 4 * n + 5); // ��������� ���� ����
			y += ch; // ���������� ����� ���� � �����
			if (n > MaxIter) {
				cout << "|\t" << x << "\t|\t" << setw(8) << "��� ����������!" << "\t|\t" << n << "\t|" << endl;
				done = false; break;
			}

		}
		if (done)cout << "|\t" << x << "\t|\t" << setw(8) << y << "\t|\t" << n << "\t|" << endl;
	}


	system("pause");
}