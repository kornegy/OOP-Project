#pragma once
#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

#include <string>

class Client //max clients - 70
{
private:
    string name;
    int age;

public:
    Client(string n, int a);

    string GetName();
    int GetAge();

    bool ageCheck(int clientAge);
};

#endif
