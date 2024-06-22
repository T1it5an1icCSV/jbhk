#include <iostream>
#include <vector>
#include <string>
#include "HeaderClient.h"
#include <locale>
#include <fstream>

using namespace std;
extern std::vector<std::string> orders;
vector<string> orders;

class Employer {
public:
    virtual void viewOrders(vector<string>& orders) = 0;
    virtual void startComplete(vector<string>& orders) = 0;
};

class Povar : public Employer {
public:
    void viewOrders(vector<string>& orders) override {
        cout << "Просмотр блюд из заказа:" << endl;
        for (const auto& order : orders) {
            cout << "Блюдо с ID " << order << endl;
        }
        cout << "Статус заказа: Передан на кухню" << endl;
    }

    void startComplete(vector<string>& orders) override {
        string userInput;
        cout << "Введите ID продуктов для проверки и готовности приготовления:" << endl;
        cin >> userInput;

        for (auto& order : orders) {
            if (order == userInput) {
                cout << "Блюдо с ID " << userInput << " приготовлено. Статус заказа изменен на 'Выполнен'" << endl;
                return;
            }
        }
        cout << "Блюдо с ID " << userInput << " отсутствует в заказе или не готово." << endl;
    }
};

class Waiter : public Employer {
public:
    void viewOrders(vector<string>& orders) override {
        cout << "Все заказы:" << endl;
        for (const auto& order : orders) {
            cout << "Блюдо с ID " << order << endl;
        }
        cout << "Статус заказа: Передан на кухню" << endl;
    }

    void startComplete(vector<string>& orders) override {
        cout << "Блюда готовы. Статус заказа изменен на 'Выполнен'" << endl;
    }
};

void waiterRole() {
    Waiter waiter;
    int choice;
    bool exit = false;
    string dishName;

    cout << "Вы перешли в роль официанта" << endl;
    do {
        // код официанта
        cout << "Выберите действие:" << endl;
        cout << "1. Просмотреть заказы" << endl;
        cout << "2. Выполнитнить заказ" << endl;
        cout << "3. Выйти из роли официанта" << endl;
        cout << "Ваш выбор: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Вы выбрали: Просмотреть заказы \n" << endl;
            cout << "Заказы (по ID): 5 \n" << endl;
            waiter.viewOrders(orders);
            break;
        case 2:
            cout << "Вы выбрали: Выполнить заказ\n" << endl;
            cout << "Заказ 5 выполнен\n" << endl;
            waiter.startComplete(orders);
            break;
        case 3:
            cout << "Вы выбрали: Выйти из роли официанта" << endl;
            exit = true;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите снова." << endl;
            break;
        }

    } while (!exit);
}

void povarRole() {
    Povar povar; 
    int choice;
    bool exit = false;
    string dishName;
    vector<string> orders; 

    cout << "Вы перешли в роль повара" << endl;
    do {
        cout << "Выберите действие:" << endl;
        cout << "1. Просмотреть заказы" << endl;
        cout << "2. Приготовить заказ" << endl;
        cout << "3. Выйти из роли повара" << endl;
        cout << "Ваш выбор: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Вы выбрали: Просмотреть заказы" << endl;
            povar.viewOrders(orders);
            break;
        case 2:
            cout << "Вы выбрали: Приготовить заказ" << endl;
            povar.startComplete(orders);
            break;
        case 3:
            cout << "Вы выбрали: Выйти из роли повара" << endl;
            exit = true;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите снова." << endl;
            break;
        }

    } while (!exit);
}
