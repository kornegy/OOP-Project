#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#define MAX_TABLES 24
#define MAX_CLIENTS 70

using namespace std;

#include <string>

class Restaurant
{
private:
	string name;
	const int maxStaff;
	string kitchenType;
	double foodRate;
	double budget;
public:
	Restaurant(string n, const int mS, string kT, double fR, double b);
	~Restaurant();

	string GetName();
	const int GetMaxStaff();
	string GetKitchenType();
	double GetFoodRate();
	double GetBudget();

	void ratingFood(bool like);
};


class Orders
{
private:
	bool orderStatus;
	string orderInfo;

public:
	Orders(bool oS, string oI);
	~Orders();

	bool GetOrderStatus();
	string GetOrderInfo();

	void makeOrder(string meal, string drink, string snack);
	
};

class Tables
{
private:
	int tablesAmount;

public:
	Tables(int tA);
	~Tables();

	int GetTablesAmount();

	void bookTable(int people);
};

#endif
