#include "Restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant(string n, const int mS, string kT, double fR, double b) : name(n), maxStaff(mS), kitchenType(kT), foodRate(fR), budget(b) {}
Restaurant::~Restaurant() {}

string Restaurant::GetName() { return name; }
const int Restaurant::GetMaxStaff() { return maxStaff; }
string Restaurant::GetKitchenType() { return kitchenType; }
double Restaurant::GetFoodRate() { return foodRate; }
double Restaurant::GetBudget() { return budget; }

void Restaurant::ratingFood(bool like)
{
	foodRate = 0;
	if (like = true)
	{
		foodRate += 0.05;
		cout << "Thank you for your support!" << endl;
		cout << "Food rate is: " << foodRate << endl << endl;
	}
	else if (like = false)
	{
		foodRate -= 0.05;
		cout << "Tell us if something wrong!" << endl<<endl;
	}
}

Orders::Orders(bool oS, string oI) : orderStatus(oS), orderInfo(oI) {}
Orders::~Orders() {}

bool Orders::GetOrderStatus() { return orderStatus; }
string Orders::GetOrderInfo() { return orderInfo; }

void Orders::makeOrder(string meal, string drink, string snack)
{
	int orderId = 0;
	if (meal.empty() && drink.empty() && snack.empty())
	{
		cout << "Your order is empty!" << endl;
		orderStatus = false;
	}
	else
	{
		cout << "Your order is: " << meal << ", " << drink << ", " << snack << endl << endl;
		orderStatus = true;
		orderId++;
	}
	cout << "Your order number: " << orderId << endl<<endl;
}

Tables::Tables(int tA) : tablesAmount(tA) {}
Tables::~Tables() {}

int Tables::GetTablesAmount() { return tablesAmount; }

void Tables::bookTable(int people)
{
	int tablesAmount = 0;
	bool status;
	if (tablesAmount >= 24)
	{
		cout << "There is no place to sit! We are sorry :(" << endl;
		status = false;
	}
	else if(people > 0 && people < 8)
	{
		cout << "You order a place for " << people << " people!" << endl << endl;
		status = true;
		people += people;
		tablesAmount += tablesAmount;
	}
}
