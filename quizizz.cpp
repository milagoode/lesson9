#include <iostream>
#include "file_chas.h"
#include <fstream>
#include <string>
using namespace std;

int quizizz() {
	system("chcp 1251>null");
	cout << "\t\n\tвікторина\n\n";
	ifstream file("qui.txt");
	if (!file) {
		cout << "файл не знайдено\n";
			return 1;
	}
	short kol = 0;
	short right =0;
	string line, variant, user;
	while (getline(file, line)) {
		cout << "питання #" << kol << endl;
		cout << line << endl;
		for (int i = 1; i <= 3; i++) {
			getline(file, line);
			cout << i << ")" << line << endl;
		}

		cout << "ваш варіант: ";
		cin >> user;
		file >> line;
		file.ignore();

		if (user == line) {
			cout << "\n\033[33m правильно\033[0m\n";
			right++;
		}
		else cout << "\n\033[32mне правильно\033[0m\n";

		kol++;
	}
	cout << "на " << kol << " питань ви відповіли вірно: " << right << endl;
	file.close();

	cout << "\t\033[41mповернутися до меню\n1) вийти\n2)\n ваш вибір: \033[0m\n";
	short choice, res;
	cin >> choice;
	if (choice == 1) res = main();
	else if (choice == 2) exit;
	else cout << "помилка\n";

	return 0;
}
