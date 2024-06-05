#include "Staff.h"
#include<iostream>
#include <vector>

using namespace std;

Staff::Staff(int a, string n, string c, string t) : age(a), name(n), contact(c), title(t) {}

int Staff::GetAge() { return age; }
string Staff::GetName() { return name; }
string Staff::GetContact() { return contact; }
string Staff::GetTitle() { return title; }

///////////////////////////////////////////////////
Administrator::Administrator(int a, string n, string c, string t, double cash, int wC, int cC, double wWH, double cWH, double wS, double cS) : Staff(a, n, c, t), cash(cash), waitersCount(wC), cooksCount(cC), waiterWorkingHours(cWH), cookerWorkingHours(cWH), wSalary(wS), cSalary(cS) {}

double Administrator::GetCash() { return cash; }
int Administrator::GetWaitersCount() { return waitersCount; }
int Administrator::GetCooksCount() { return cooksCount; }
double Administrator::GetWaiterWorkingHours() { return waiterWorkingHours; }
double Administrator::GetCookerWorkingHours() { return cookerWorkingHours; }

void Administrator::waiterSalaryPayment(int month, double waiterWorkingHours)
{
	double WSalary = 1800;
	if (month == 30 && waiterWorkingHours >= 115)
	{
		if (GetCash() >= 20000)
		{
			cout << "Salary successfully payed: " << WSalary << endl << endl;
		}
	}
	else if (month < 30 && GetWaiterWorkingHours() < 135)
	{
		double expWSalary = WSalary / 2;
		cout << "Not enough working time pay the full salary!" << endl << "Salary right now is: " << expWSalary << endl << endl;
	}
}
void Administrator::cookerSalaryPayment(int month, double cookerWorkingHours)
{
	double CSalary = 2500;
	if (month == 30 && cookerWorkingHours >= 135)
	{
		if (GetCash() >= 20000)
		{
			cout << "Salary successfully payed: " << CSalary << endl << endl;
		}
	}
	else if (month < 30 && GetCookerWorkingHours() < 135)
	{
		double expCSalary = CSalary / 2;
		cout << "Not enough working time pay the full salary!" << endl << "Salary right now is: " << expCSalary << endl << endl;
	}
}

void Administrator::addCooker(const int cookerId)
{
	cooksCount = 6;
	if (GetCooksCount() < 7)
	{
		waiters.push_back(cookerId);
		waitersCount++;
		cout << "Cooker is hired!" << endl << endl;
	}
	else
	{
		cout << "There is no place to hire cooker!" << endl << endl;
	}
}
void Administrator::deleteCooker(const int cookerId)
{
	if (GetCooksCount() > 0)
	{
		auto it1 = find(cookers.begin(), cookers.end(), cookerId);
		if (it1 != cookers.end())
			cookers.erase(it1);
	}
	cooksCount--;
}
void Administrator::addWaiter(const int waiterId)
{
	waitersCount = 6;
	if (GetWaitersCount() < 6)
	{
		waiters.push_back(waiterId);
		waitersCount++;
		cout << "Waiter if hired!" << endl << endl;
	}
	else
	{
		cout << "There is no place to hire waiter!" << endl << endl;
	}
}
void Administrator::deleteWaiter(const int waiterId)
{
	if (GetWaitersCount() > 0)
	{
		auto it1 = find(waiters.begin(), waiters.end(), waiterId);
		if (it1 != waiters.end())
			waiters.erase(it1);
	}
	waitersCount--;
}

//////////////////////////////////////////////
Waiters::Waiters(int a, string n, string c, string t, double wH) : Staff(a, n, c, t) {}

void Waiters::takeOrders(int orderId)
{
	if (orderId != 0)
		activeOrders.push_back(orderId);

	cout << "The order number " << orderId << " has been taken" << endl << endl;
}
void Waiters::sendOrderToKitchen(Cooks& cooks, int orderId)
{
	// Проверяем, есть ли такой заказ в списке активных заказов
	bool found = false;
	for (int order : activeOrders) 
	{
		if (order == orderId) 
		{
			found = true;
			break;
		}
	}

	if (found) 
	{
		cooks.cooking();
	}
	else
	{
		cout << "Error: Order number " << orderId << " not found.\n";
	}
}
//////////////////////////////////////////////
Cooks::Cooks(int a, string n, string c, string t, double wH) : Staff(a, n, c, t) {}

void Cooks::cooking() 
{
	cout << "Cooking...\n";
	cout << "Done cooking!\n" << endl;
}