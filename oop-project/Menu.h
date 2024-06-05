#pragma once
#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

using namespace std;

// Структура для хранения информации о каждом элементе меню
struct MenuItem 
{
    string name;
    double price;
    bool isAlcoholic;
};

class Menu
{
private:
    string menu_info;

protected:
    vector<MenuItem> items;

public:
    Menu(string mi);
    virtual ~Menu() {}

    // Методы для управления элементами меню
    void addItem(const string& name, double price);
    void deleteItem(const string& name);

    virtual void displayMenu() = 0;
};

class Meals : public Menu
{
public:
    Meals(string mi);
    ~Meals() {}

    void displayMenu() override;
};

class Drinks : public Menu
{
public:
    Drinks(string mi);
    ~Drinks() {}

    // Добавим отдельный метод для добавления напитков с указанием алкогольности
    void addDrink(const string& name, double price, bool isAlcoholic);

    void displayMenu() override;
};

class Snacks : public Menu
{
public:
    Snacks(string mi);
    ~Snacks() {}

    void displayMenu() override;
};

#endif
