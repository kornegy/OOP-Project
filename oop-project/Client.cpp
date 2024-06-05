#include "Client.h"

using namespace std;

Client::Client(string n, int a) : name(n), age(a) {}

string Client::GetName() { return name; }
int Client::GetAge() { return age; }

bool Client::ageCheck(int clientAge)
{
	bool alco;
	if (clientAge < 18)
		 return alco = false;

	return alco = true;
}
