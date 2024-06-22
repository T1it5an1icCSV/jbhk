#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
#include <Windows.h>
#include <string>

using namespace std;

string path = "Menu.txt";
string path1 = "Employers.txt";
string path2 = "Clients.txt";

fstream fs;

struct Product
{
    string id;
    string name;
    string price;
};

vector<Product> products;

struct Dish
{
    string id;
    string name;
    string price;
    string productsList;
    int cookTime;
};

void adminRole() {
    int adminChoice;

    do {
        cout << "Добро пожаловать, Системный администратор (вставьте логин системного администратора)!\n";
        cout << "1. Редактировать меню\n";
        cout << "2. Редактировать учетные записи сотрудников\n";
        cout << "3. Просмотреть всех пользователей\n";
        cout << "4. Редактировать список продуктов\n";
        cout << "9. Выход\n";

        while (!(cin >> adminChoice) || adminChoice < 1 || adminChoice > 9) {
            cout << "Некорректный ввод. Пожалуйста, выберите соответствующую цифру.\n";
            cin.clear();
            
        }

        switch (adminChoice) {
        case 1:
        {
            int menuChoice;

            do {
                cout << "Меню редактирования:\n";
                cout << "1. Редактировать меню\n";
                cout << "4. Вернуться в меню системного администратора\n";

                while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 4) {
                    cout << "Некорректный ввод. Пожалуйста, выберите соответствующую цифру (1-4).\n";
                    cin.clear();
                    
                }

                switch (menuChoice) {
                case 1:
                    fs.open(path, fstream::in | fstream::out | fstream::app);
                    if (!fs.is_open())
                    {
                        cout << "Ошибка при открытии файла" << endl;
                    }
                    else
                    {
                        string id, name, price, productsList, cookTime;
                        int value;
                        string msg;
                        cout << "Файл успешно открыт" << endl;
                        cout << "1. Добавить записи" << endl;
                        cout << "2. Просмотреть все записи" << endl;
                        cout << "3. Удалить записи(по названию блюда)" << endl;
                        cout << "Введите выбор: ";
                        cin >> value;
                        if (value == 1)
                        {
                            SetConsoleCP(1251);
                            string productsList;
                            int cookTime;

                            cout << "Введите ID блюда: ";
                            cin >> id;
                            cout << "Введите название блюда: ";
                            cin >> name;
                            cout << "Введите цену блюда: ";
                            cin >> price;
                            cout << "Введите айди продуктов через пробел: ";
                            cin.ignore();
                            getline(cin, productsList);
                            cout << "Введите примерное время приготовления (в минутах): ";
                            cin >> cookTime;

                            fs << id << " " << name << " " << price << " " << productsList << " " << cookTime << "\n";

                            SetConsoleCP(866);
                        }

                        else if (value == 2)
                        {
                            SetConsoleCP(1251);
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

                                SetConsoleCP(866);
                            }
                        }

                        else if (value == 3)
                        {
                            SetConsoleCP(1251);
                            string deleteMsg;
                            cin >> deleteMsg;

                            fstream tempFile("Menu.txt", fstream::out);

                            while (!fs.eof())
                            {
                                msg = "";
                                fs >> msg;
                                if (msg != deleteMsg)
                                {
                                    tempFile << msg << "\n";
                                }
                            }
                            tempFile.close();
                            fs.close();
                            remove(path.c_str());
                            rename("Menu.txt", path.c_str());
                            SetConsoleCP(866);
                        }
                    }
                    fs.close();
                    break;

                case 4:
                    cout << "Возврат в основное меню...\n";
                    break;
                default:
                    cout << "Некорректный выбор. Попробуйте еще раз.\n";
                }

            } while (menuChoice != 4);

            break;
        }

        case 2:
            SetConsoleCP(1251);
            fs.open(path1, fstream::in | fstream::out | fstream::app);
            if (!fs.is_open())
            {
                cout << "Ошибка при открытии файла" << endl;
            }
            else
            {
                string fio, position, employeeId, login, password;
                int choice;
                cout << "Файл успешно открыт" << endl;
                cout << "1. Добавить запись" << endl;
                cout << "2. Просмотреть все записи" << endl;
                cout << "3. Удалить запись (по ID)" << endl;
                cout << "Введите выбор: ";
                cin >> choice;

                if (choice == 1)
                {
                    cout << "Введите ФИО сотрудника: ";
                    cin.ignore();
                    getline(cin, fio);

                    cout << "Введите ID сотрудника: ";
                    cin >> employeeId;

                    cout << "Введите должность сотрудника: ";
                    cin.ignore();
                    getline(cin, position);

                    cout << "Введите логин сотрудника: ";
                    cin >> login;

                    cout << "Введите пароль сотрудника: ";
                    cin >> password;

                    fs << fio << " " << employeeId << " " << position << " " << login << " " << password << "\n";
                }

                else if (choice == 2)
                {
                    cout << "Данные из файла успешно загружены" << endl;
                    while (fs >> fio >> employeeId >> position >> login >> password)
                    {
                        cout << "ФИО: " << fio << ", ID: " << employeeId << ", Должность: " << position << ", Логин: " << login << ", Пароль: " << password << endl;
                        SetConsoleCP(866);
                    }
                }

                else if (choice == 3)
                {
                    SetConsoleCP(1251);
                    string deleteId;
                    cout << "Введите ID сотрудника для удаления: ";
                    cin >> deleteId;

                    fstream tempFile("Empoyers.txt", fstream::out);

                    while (!fs.eof())
                    {
                        fs >> fio >> position >> employeeId >> login >> password;
                        if (employeeId != deleteId)
                        {
                            tempFile << fio << " " << position << " " << employeeId << " " << login << " " << password << "\n";
                        }
                    }
                    tempFile.close();
                    fs.close();
                    remove(path1.c_str());
                    rename("tempempoyers.txt", path1.c_str());
                }
            }
            fs.close();
            SetConsoleCP(866);
            break;

        case 3:
        {
            SetConsoleCP(1251);
            fstream clientsFile("Clients.txt", fstream::in | fstream::out | fstream::app);
            if (!clientsFile.is_open())
            {
                cout << "Ошибка при открытии файла" << endl;
            }
            else
            {
                string clientId, clientName;
                int choice;

                cout << "Файл с информацией о клиентах успешно открыт" << endl;
                cout << "1. Зарегистрировать клиента" << endl;
                cout << "2. Просмотреть список клиентов" << endl;
                cout << "Введите выбор: ";
                cin >> choice;

                if (choice == 1)
                {
                    cout << "Введите ID клиента: ";
                    cin >> clientId;
                    cout << "Введите имя клиента: ";
                    cin.ignore();
                    getline(cin, clientName);

                    clientsFile << clientId << " " << clientName << "\n";
                    cout << "Клиент успешно зарегистрирован" << endl;
                }
                else if (choice == 2)
                {
                    cout << "Список зарегистрированных клиентов:" << endl;
                    clientsFile.clear();
                    clientsFile.seekg(0, ios::beg);

                    while (clientsFile >> clientId >> clientName)
                    {
                        cout << "ID: " << clientId << ", Имя: " << clientName << endl;
                    }
                }
            }
            clientsFile.close();
            SetConsoleCP(866);
            break;
        }
        case 4:
        {
            int choice;
            cout << "1. Просмотреть список продуктов" << endl;
            cout << "2. Добавить продукт" << endl;
            cout << "3. Удалить продукт" << endl;
            cin >> choice;

            if (choice == 1)
            {
                for (const Product& product : products)
                {
                    cout << "ID: " << product.id << " Название: " << product.name << " Цена: " << product.price << endl;
                }
            }
            else if (choice == 2)
            {
                Product newProduct;
                cout << "Введите ID продукта: ";
                cin >> newProduct.id;
                cout << "Введите название продукта: ";
                cin >> newProduct.name;
                cout << "Введите цену продукта: ";
                cin >> newProduct.price;

                products.push_back(newProduct);
                cout << "Продукт успешно добавлен" << endl;
            }
            else if (choice == 3)
            {
                string productId;
                cout << "Введите ID продукта для удаления: ";
                cin >> productId;

                for (auto it = products.begin(); it != products.end(); ++it)
                {
                    if (it->id == productId)
                    {
                        products.erase(it);
                        cout << "Продукт с ID " << productId << " успешно удален" << endl;
                        break;
                    }
                }
                cout << "Продукт с ID " << productId << " не найден" << endl;
            }
            break;
        }
        case 9:
            cout << "Выход из роли администратора.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
        }
    } while (adminChoice != 9);
}

