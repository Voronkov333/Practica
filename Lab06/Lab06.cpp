#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	const int l_fam = 20, l_name = 20, l_namber = 12;
	char numb[l_namber];
	int n = 0;
	cout << "������� ����������� �����: " << endl; cin >> n;
	struct NOTE {
		char fam[l_fam];
		char name[l_name];
		char namber_t[l_namber];
		int dt[3];
	};
	NOTE S1;
	NOTE *S2 = new NOTE[n];

	for (int j = 0; j < n; j++) {
		cout << " ������� ������ �������� � " << j + 1 << endl;
		cout << " ������� �������: ";
		cin.getline(S2[j].fam, l_fam + 1);
		OemToChar(S2[j].fam, S2[j].fam);
		cin.getline(S2[j].fam, l_fam + 1);
		OemToChar(S2[j].fam, S2[j].fam);

		cout << " ������� ���: ";
		cin.getline(S2[j].name, l_name + 1);
		OemToChar(S2[j].name, S2[j].name);

		cout << " ������� ����� ��������: ";
		cin.getline(S2[j].namber_t, l_namber + 1);
		OemToChar(S2[j].namber_t, S2[j].namber_t);

		cout << "������� ���� ��������:" << endl;
		cout << "������� �����: "; cin >> S2[j].dt[0];
		cout << "������� �����: "; cin >> S2[j].dt[1];
		cout << "������� ���: "; cin >> S2[j].dt[2];

	}
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
	cout << "-----------------------------------����������-----------------------------------" << endl;
	cout << "\n������, ������������� �� ���� ��������: " << endl;
	for (int j = 0; j < n; j++) {
		cout << "�������: " << S2[j].fam << endl << "���: " << S2[j].name << endl << "����� ��������: " << S2[j].namber_t << endl << "���� ��������: ";
		for (int i = 0; i < 3; i++)cout << S2[j].dt[i] << ".";
		cout << endl;
	}

	cout << "\n������� ����� ��� ������: ";
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
	if (cnt == false)cout << "������ �������� � ���� ���!" << endl;
	cout << endl;
	system("pause");
}