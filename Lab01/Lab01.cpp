#include <iostream>
#include <math.h>
#pragma warning(disable : 4996)
void main() {
	setlocale(LC_ALL, "Russian");
	int a;
	double pi = acos(-1);
	double z1, z2;
	printf("¬ведите целое число:\n");
	scanf("%d", &a);
	z1 = (sin(4 * a) / (1 + cos(4 * a)))*(cos(2 * a) / (1 + cos(2 * a)));
	z2 = 1 / tan(1.5*pi - a);
	printf("z1(%d) = %f\n", a, z1);
	printf("z2(%d) = %f\n", a, z2);
	system("pause");
}