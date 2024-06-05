#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(string mi) : menu_info(mi) {}

void Menu::addItem(const string& name, double price)
{
    items.push_back({ name, price });
}

void Menu::deleteItem(const string& name)
{
    auto it = find_if(items.begin(), items.end(), [&name](const MenuItem& item) {
        return item.name == name;
        });
    if (it != items.end())
        items.erase(it);
}

void Menu::displayMenu() // »справлено: метод объ€влен как константный
{
    cout << "Menu items:" << endl;
    for (const auto& item : items)
    {
        cout << item.name << " - " << item.price << "$" << endl;
    }
}

Meals::Meals(string mi) : Menu(mi) {}

void Meals::displayMenu() // »справлено: метод объ€влен как константный
{
    cout << "Meals in the menu:" << endl;
    Menu::displayMenu();
}

Drinks::Drinks(string mi) : Menu(mi) {}

void Drinks::addDrink(const string& name, double price, bool isAlcoholic)
{
    addItem(name, price); // »справлено: добавл€ем напиток через метод addItem
    items.back().isAlcoholic = isAlcoholic; // ƒобавим информацию о том, алкогольный ли напиток
}

void Drinks::displayMenu()  // »справлено: метод объ€влен как константный
{
    cout << "Drinks in the menu:" << endl;
    for (const auto& item : items)
    {
        cout << item.name << " - " << item.price << "$ " << (item.isAlcoholic ? "- alcoholic drink!" : "- non-alcoholic drink!") << endl;
    }
}

Snacks::Snacks(string mi) : Menu(mi) {}

void Snacks::displayMenu()  // »справлено: метод объ€влен как константный
{
    cout << "Snacks in the menu:" << endl;
    Menu::displayMenu();
}
