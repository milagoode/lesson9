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
		cout << "���� �� ��������\n";
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
		cout << "���������� ���\n";
		return;
	}
	cout << "������ ��'� �� ����� �������� ������ ��������: ";
	cin >> tb[count].name >> tb[count].phone;
	ofstream file("contact.txt", ios::app);
	if (file) {
		file << tb[count].name << " " << tb[count].phone << endl;
		count++;
		cout << "������� ������\n";
	}
	else {
		cout << "�������\n";
	}
}

void editContact(telbook tb[], int count) {
	string searchName;
	cout << "������ ��'� �������� ��� �����������: ";
	cin >> searchName;
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (tb[i].name == searchName) {
			cout << "������ ���� ��'� �� ����� ��������: ";
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
		cout << "������� ������\n";
	}
	else {
		cout << "������� �� ��������\n";
	}
}

void findContact(telbook tb[], int count) {
	string searchCon;
	cout << "������ ��'� ��� ����� �������� ��� ������: ";
	cin >> searchCon;
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (tb[i].name == searchCon || tb[i].phone == searchCon) {
			cout << "��������: " << tb[i].name << ' ' << tb[i].phone << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "������� �� ��������\n";
	}
}

int phonebook() {
	system("chcp 1251>null");
	short contact;
	int size = 0;
	telbook tb[10];
	beginContact(tb, size);
	cout << "\t\n\t��������� �����\n\n";
	cout << "1 - �������� �������\n 2 - ������ �������\n 3 - ���������� �������\n 4 - ������ �������\n 0 - �����";
	while (true) {
		cout << "\n������ �����: ";
		cin >> contact;
		switch (contact) {
		case 0:
			cout << "�����\n";
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
			cout << "����������� �����\n";
		}
	}
}
