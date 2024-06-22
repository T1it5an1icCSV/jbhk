#include "HeaderClient.h"
#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <vector>

#include "HeaderAdmin.h"
using namespace std;
extern basic_fstream<char, struct char_traits<char>> fs;


struct MenuItem {
    string id;
    string name;
    float price;
    string productsList;
    string cookTime;
};

vector<MenuItem> menuItems;
vector<MenuItem> cart;

MenuItem item;
bool found = false;

void loadMenuItems() {
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
    }
    else {
        string id, name, price, productsList, cookTime;
        cout << "Данные из файла успешно загружены" << endl;
        while (!fs.eof()) {
            fs >> id >> name >> price >> productsList >> cookTime;
            MenuItem newItem = { id, name, stof(price), productsList, cookTime };
            menuItems.push_back(newItem);
        }
        fs.close();
    }
}

void clientRole()
{
    int choice;
    bool exit = false;
    string dishName;

    do {
        cout << "Выберите действие:" << endl;
        cout << "1. Просмотреть меню" << endl;
        cout << "2. Добавить блюда в корзинудтвердить тоже там же" << endl;
        cout << "4. Отследить статус заказа" << endl;
        cout << "5. Выйти из роли клиента" << endl;
        cout << "Ваш выбор: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Вы выбрали: Просмотреть меню" << endl;
            fs.open(path, fstream::in | fstream::out | fstream::app);
            if (!fs.is_open())
            {
                cout << "Ошибка при открытии файла" << endl;
            }
            else
            {
                string id, name, price, productsList, cookTime;
                cout << "Данные из файла успешно загружены" << endl;
                while (!fs.eof())
                {
                    id = "";
                    name = "";
                    price = "";
                    productsList = "";
                    cookTime = "";

                    fs >> id >> name >> price >> productsList >> cookTime;
                    cout << "ID: " << id << ", Название: " << name << ", Цена: " << price << ", Продукты: " << productsList << ", Время приготовления: " << cookTime << " минут" << endl;
                }
                fs.close();
            }
            break;
        case 2:
        {
            cout << "Вы выбрали: Добавить блюдо в корзину" << endl;

            string wordFromUser;
            cout << "Введите ID блюда для добавления: ";
            cin >> wordFromUser;

            ifstream inFile("Menu.txt");
            string wordFromFile = "";
            bool wordFound = false;
            vector<string> orders;

            while (inFile >> wordFromFile) {
                if (wordFromFile == wordFromUser) {
                    wordFound = true;
                    orders.push_back(wordFromFile);
                    cout << "Блюдо добавлено!" << endl;
                    cout << "Хотите продолжить заказ? (Да/Нет): ";
                    string continueOrder;
                    cin >> continueOrder;
                    if (continueOrder != "Да") {
                        break;
                    }
                }
            }

            inFile.close();

            if (!wordFound) {
                cout << "Блюдо не найдено." << endl;
            }
            else {
                cout << "Блюда в вашей корзине:" << endl;
                for (const auto& order : orders) {
                    cout << "Блюдо с ID " << order << endl;
                }

                cout << "Статус заказа: Передан на кухню" << endl;
            }

            break;
        }

        case 4:
            cout << "Вы выбрали: Отследить статус заказа" << endl;
            cout << "Передан на кухню" << endl;
            break;
        case 5:
            cout << "Вы выбрали: Выйти из роли клиента" << endl;
            exit = true;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите снова." << endl;
            break;
        }

    } while (!exit);
}

