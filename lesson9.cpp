#include <iostream>
#include "quizizz.h"
#include "phonebook.h"
#include <fstream>

using namespace std;


int main(){
    system("chcp 1251>null");
    cout << "розподіл файлу на декілька частин\n";
    cout << "\t\033[41mменю\n1) вікторина\n2) телефонна книга\n ваш вибір: \033[0m";
    short choice, res;
    cin >> choice;
    switch (choice) {
    case 1: 
        res = quizizz();//основну функцію іншого файла
        break;
    case 2:
        res = phonebook();
        break;
    default: cout << "не правильний вибір"; break;
    }
}
