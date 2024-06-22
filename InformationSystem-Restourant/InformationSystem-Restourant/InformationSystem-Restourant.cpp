#include <iostream>
#include <locale>
#include <limits>
#include "HeaderAdmin.h"
#include "HeaderEmpoyers.h"
#include "HeaderClient.h"

int main() {

    int choice;
    using namespace std;
    setlocale(LC_ALL, "Russian");

    do {
        cout << "Добро пожаловать в Информационную систему - Ресторан! \n";
        cout << "Пожалуйста, выберите вашу роль:\n";
        cout << "1. Системный администратор\n";
        cout << "2. Повар\n";
        cout << "3. Официант\n";
        cout << "4. Клиент\n";
        cout << "9. Выход\n";

        while (!(cin >> choice) || choice < 1 || choice > 4 && choice != 9) {
            cout << "Некорректный ввод. Пожалуйста, выберите соответствующую цифру из списка.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        switch (choice) {
        case 1:
            cout << "Вы выбрали роль Системного администратора.\n";
            adminRole();
            break;
        case 2:
            cout << "Вы выбрали роль Повара.\n";
            povarRole();
            break;
        case 3:
            cout << "Вы выбрали роль Официанта.\n";
            waiterRole();
            break;
        case 4:
            cout << "Вы выбрали роль Клиента.\n";
            clientRole();
            break;
        case 9:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
        }

    } while (choice != 9);

    return 0;
}
