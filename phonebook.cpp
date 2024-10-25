#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct telbook {
	string name;
	string phone;
};

void beginContact(telbook tb[], int& count) {
	ifstream file("contact.txt");
	if (!file) {
		cout << "файл не знайдено\n";
		return;
	}
	else {
		while (file >> tb[count].name >> tb[count].phone) {
			count++;
		}
		file.close();
	}
}

void showContact(telbook tb[], int count) {
	for (int i = 0; i < count; i++) {
		cout << tb[i].name << ' ' << tb[i].phone << endl;
	}
}

void addContact(telbook tb[], int& count) {
	if (count >= 10) {
		cout << "перевищено ліміт\n";
		return;
	}
	cout << "введіть ім'я та номер телефону нового контакту: ";
	cin >> tb[count].name >> tb[count].phone;
	ofstream file("contact.txt", ios::app);
	if (file) {
		file << tb[count].name << " " << tb[count].phone << endl;
		count++;
		cout << "контакт додано\n";
	}
	else {
		cout << "помилка\n";
	}
}

void editContact(telbook tb[], int count) {
	string searchName;
	cout << "введіть ім'я контакту для редагування: ";
	cin >> searchName;
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (tb[i].name == searchName) {
			cout << "введіть нове ім'я та номер телефону: ";
			cin >> tb[i].name >> tb[i].phone;
			found = true;
			break;
		}
	}
	if (found) {
		ofstream file("contact.txt");
		for (int i = 0; i < count; i++) {
			file << tb[i].name << " " << tb[i].phone << endl;
		}
		cout << "контакт змінено\n";
	}
	else {
		cout << "контакт не знайдено\n";
	}
}

void findContact(telbook tb[], int count) {
	string searchCon;
	cout << "введіть ім'я або номер телефону для пошуку: ";
	cin >> searchCon;
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (tb[i].name == searchCon || tb[i].phone == searchCon) {
			cout << "знайдено: " << tb[i].name << ' ' << tb[i].phone << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "контакт не знайдено\n";
	}
}

int phonebook() {
	system("chcp 1251>null");
	short contact;
	int size = 0;
	telbook tb[10];
	beginContact(tb, size);
	cout << "\t\n\tтелефонна книга\n\n";
	cout << "1 - показати контакт\n 2 - додати контакт\n 3 - редагувати контакт\n 4 - знайти контакт\n 0 - вихід";
	while (true) {
		cout << "\nоберіть опцію: ";
		cin >> contact;
		switch (contact) {
		case 0:
			cout << "вихід\n";
			return 0;
		case 1:
			showContact(tb, size);
			break;
		case 2:
			addContact(tb, size);
			break;
		case 3:
			editContact(tb, size);
			break;
		case 4:
			findContact(tb, size);
			break;
		default:
			cout << "неправильна опція\n";
		}
	}
}
