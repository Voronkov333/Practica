#include <fstream> 
#include <iostream>
using namespace std;

const int l_term = 17, l_text = 440;
struct TEXT {
	char term[l_term];
	char text[l_text];
	TEXT *next;
};
TEXT* add(TEXT *beg, const TEXT &man);
TEXT* find(TEXT *beg, char *name, TEXT *& prev);
void find_term(TEXT *beg);
void get_term(char *term, int l_term);
int menu();
void print_dbase(TEXT *beg);
TEXT* read_dbase(const char *filename);
// -------------------------------------- ������� ������� ---------------------------------------------------------------------
int main() {

	setlocale(LC_ALL, "Russian");
	TEXT *beg = read_dbase("dbase.txt");
	if (!beg || beg == NULL) return 1;
	while (true) {
		switch (menu()) {
		case 1: find_term(beg); break;
		case 2: print_dbase(beg); break;
		case 3: return 0;
		default: cout << " ���� ������� ����� �� 1 �� 3" << endl; break;
		}
	}
}
TEXT* add(TEXT *beg, const TEXT &text) { // ------------------- ���������� �������
	TEXT* pv = new TEXT; // ������������ ������ ��������
	*pv = text;
	pv->next = 0;
	if (beg) { // ������ �� ����
		TEXT* temp = beg;
		while (temp->next) temp = temp->next; // ����� ����� ������
		temp->next = pv; // ������������ ������ ��������
	}
	else beg = pv; // ������ ����
	return beg;
}
// ---------------------------------------------------- ����� ������ �� �������
TEXT* find(TEXT* pv, char* name, TEXT *& prev) {
	prev = 0;
	while (pv) {
		if (strstr(pv->term, name)) {
			cout << "\n" << pv->text << endl;
			return pv;
		}
		prev = pv;
		pv = pv->next;
	}
	cout << "������ ������� � ���� ���\n" << endl;
	return 0;
}
void find_term(TEXT* beg) { // ---------------------------------------------- �����
	char buf[l_term];
	TEXT *prev = 0, *pv = 0;
	get_term(buf, l_term);
	pv = find(beg, buf, prev);
}
int menu() { // -------------------------------------------------------- ����� ����
	char buf[10];
	int option;
	do {
		cout << endl << "===========================================================" << endl;
		cout << "1 - ����� ������ �� �������" << endl;
		cout << "2 - ����� ����� ����� �� �����\n3 - �����" << endl;
		cin.getline(buf, 10);
		option = atoi(buf);
	} while (!option);
	return option;
}
void print_dbase(TEXT* beg) { // ----------------------------- ����� ���� �� �����
	TEXT* pv = beg;
	while (pv) {
		cout << pv->term << "\n" << pv->text << endl;
		pv = pv->next;
	}
}
TEXT* read_dbase(const char* filename) { // ----------------------- ������ ���� �� �����

	ifstream fin(filename);
	if (!fin) { cout << "������ �������� �����." << endl; return NULL; }

	fin.ignore(numeric_limits<streamsize>::max());
	streamsize len = fin.gcount();
	fin.clear();   //  Since ignore will have set eof.
	fin.seekg(0, ios_base::beg);

	int i = 0, n = 0, j = 0, m = 0, cnt = 1;

	TEXT text, *beg = 0;
	char *buf = new char[len + 1];
	fin.seekg(0, ios::beg);
	fin.read(buf, len);
	buf[len] = '\0';

	while (buf[i]) {
		switch (cnt) {
		case 1:
			if (buf[i] == '\n' || buf[i] == '\0') {
				for (j = n, m = 0; j < i; j++, m++) {
					text.term[m] = buf[j];
				}
				cnt = 2; n = i + 1; text.term[m] = '\0';
			}
			break;
		case 2:
			if (buf[i] == '\n' || buf[i] == '\0') {
				for (j = n, m = 0; j <= i; j++, m++) {
					text.text[m] = buf[j];
				}
				cnt = 1; n = i + 1, text.text[m] = '\0'; beg = add(beg, text);
			}
			break;
		}
		i++;
	}
	cout << buf;
	return beg;
}
#include <windows.h>
void get_term(char* term, int l_term) { // ----------------------------------- ������ �������
	cout << "������� ������: " << endl; cin.getline(term, l_term); OemToChar(term, term); term[strlen(term)] = '\0';
}
