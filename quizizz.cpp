#include <iostream>
#include "file_chas.h"
#include <fstream>
#include <string>
using namespace std;

int quizizz() {
	system("chcp 1251>null");
	cout << "\t\n\t��������\n\n";
	ifstream file("qui.txt");
	if (!file) {
		cout << "���� �� ��������\n";
			return 1;
	}
	short kol = 0;
	short right =0;
	string line, variant, user;
	while (getline(file, line)) {
		cout << "������� #" << kol << endl;
		cout << line << endl;
		for (int i = 1; i <= 3; i++) {
			getline(file, line);
			cout << i << ")" << line << endl;
		}

		cout << "��� ������: ";
		cin >> user;
		file >> line;
		file.ignore();

		if (user == line) {
			cout << "\n\033[33m ���������\033[0m\n";
			right++;
		}
		else cout << "\n\033[32m�� ���������\033[0m\n";

		kol++;
	}
	cout << "�� " << kol << " ������ �� ������� ����: " << right << endl;
	file.close();

	cout << "\t\033[41m����������� �� ����\n1) �����\n2)\n ��� ����: \033[0m\n";
	short choice, res;
	cin >> choice;
	if (choice == 1) res = main();
	else if (choice == 2) exit;
	else cout << "�������\n";

	return 0;
}
