#include <fstream>
#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream fin("text.txt", ios::in);
	if (!fin) {
		cout << " Ошибка " << endl; return 1;
	};
	fin.seekg(0, ios::end);
	bool cnt = false;
	long len = fin.tellg();
	char*buf = new char[len + 1];
	fin.seekg(0, ios::beg);
	fin.read(buf, len);
	long i = 0;
	cout << "предложения с тире в начале:\n";
	while (buf[i] != '\0') {
		if (buf[i] == '-' && buf[i - 1] == ' ') {
			cnt = true;
			while (buf[i - 1] != '.' && buf[i] != '\0') {
				cout << buf[i]; i++;
			}
			cout << endl;
		}
		i++;
	}
	if (cnt == false) { cout << "Таких предложений нет"; }
	fin.close();
	cout << endl;
	system("PAUSE");
	return 0;
}
