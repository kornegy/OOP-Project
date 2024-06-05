#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Client.h"
#include "Menu.h"
#include "Restaurant.h"
#include "Staff.h"

int main()
{
	Client client1("Brad Pit", 23);
	cout << "Client name: " << client1.GetName() << endl << "Client age: " << client1.GetAge() << endl << endl;

	Meals meals1("Breakfast Menu");
	meals1.addItem("Eggs Benedict", 8.99);
	meals1.addItem("Pancakes", 6.49);

	Drinks drinks1("Beverages");
	drinks1.addItem("Juice", 1.99);
	drinks1.addDrink("Coffee", 2.49, false);
	drinks1.addDrink("Orange Juice", 3.99, false);
	drinks1.addDrink("Martini", 10.99, true);

	Snacks snacks1("Desserts");
	snacks1.addItem("Cheesecake", 4.99);
	snacks1.addItem("Brownie", 3.49);

	cout << "=== Breakfast Menu ===" << endl;
	meals1.displayMenu();
	cout << endl;

	cout << "=== Beverages ===" << endl;
	drinks1.displayMenu();
	cout << endl;

	cout << "=== Desserts ===" << endl;
	snacks1.displayMenu();
	cout << endl;

	Administrator admin(48, "Sam Sulek", "admin.sam_sulek.gmail.com", "Restaurant admin", 100000);

	admin.addWaiter(1);
	admin.addCooker(1);

	admin.waiterSalaryPayment(25, 140);
	admin.cookerSalaryPayment(25, 135);

	Waiters waiters1(27, "Jhony Sins", "123-456-7890", "Waiter");
	Cooks chef(30, "Mike", "987-654-3210", "Chef");
	waiters1.takeOrders(2);
	waiters1.sendOrderToKitchen(chef, 2);

	Restaurant restaurant1("GoldServ", 13, "Japanese", 4.5, 100000.0);
	cout << "Name of restaurant: " << restaurant1.GetName() << endl << "Max of staff: " << restaurant1.GetMaxStaff() << endl << "Type of kitchen: " << restaurant1.GetKitchenType() << endl << "Rate: " << restaurant1.GetFoodRate() << endl << "Budget: " << restaurant1.GetBudget()<<"$" << endl << endl;

	restaurant1.ratingFood(true);

	Orders order1(true, "Soon...");
	order1.makeOrder("Potato", "Cola", "Chips");

	Tables tables1(24);
	tables1.bookTable(4);

	return 0;
}