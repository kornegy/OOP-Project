#ifndef STAFF_H
#define STAFF_H

#define MAX_WAITERS 6
#define MAX_COOKERS 7

#include <string>
#include <vector>
using namespace std;

class Staff
{
private:
    int age;
    string name;
    string contact;
    string title;

public:
    Staff(int a, string n, string c, string t);

    int GetAge();
    string GetName();
    string GetContact();
    string GetTitle();
};

// Предварительное объявление классов Waiters и Cooks
class Waiters;
class Cooks;

class Administrator : public Staff
{
private:
    double cash;

    double wSalary;
    double cSalary;

    int waitersCount;
    double waiterWorkingHours;

    int cooksCount;
    double cookerWorkingHours;

protected:
    vector<int>waiters;
    vector<int>cookers;

public:
    Administrator(int a, string n, string c, string t, double cash, int wC = 0, int cC = 0, double wWH = 0.0, double cCH = 0.0, double wSalary = 0.0, double cSalary = 0.0);

    double GetCash();
    int GetWaitersCount();
    int GetCooksCount();

    double GetWaiterWorkingHours();
    double GetCookerWorkingHours();

    void waiterSalaryPayment(int month, double workingHours);
    void cookerSalaryPayment(int month, double workingHours);

    void addWaiter(const int waiterId);
    void deleteWaiter(const int waiterId);

    void addCooker(const int cookerId);
    void deleteCooker(const int cookerId);
};

class Waiters : public Staff
{
protected:
    vector<int>activeOrders;

public:
    Waiters(int a, string n, string c, string t, double wH = 0.0);

    void takeOrders(int orderId);
    void sendOrderToKitchen(Cooks& cooks, int orderId);
};

class Cooks : public Staff
{
public:
    Cooks(int a, string n, string c, string t, double wH = 0.0);

    void cooking();
};

#endif
