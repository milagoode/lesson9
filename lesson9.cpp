#include <iostream>
#include "quizizz.h"
#include "phonebook.h"
#include <fstream>

using namespace std;


int main(){
    system("chcp 1251>null");
    cout << "������� ����� �� ������� ������\n";
    cout << "\t\033[41m����\n1) ��������\n2) ��������� �����\n ��� ����: \033[0m";
    short choice, res;
    cin >> choice;
    switch (choice) {
    case 1: 
        res = quizizz();//������� ������� ������ �����
        break;
    case 2:
        res = phonebook();
        break;
    default: cout << "�� ���������� ����"; break;
    }
}
