#include <fstream>
#include <iostream>
#include "WorkWithAccounts.h"

struct userData
{
	string login;
	string password;
	string salt;
	bool isAccess = false;
	bool isAdministrator = false;
};
int main()
{
	do
	{
		switch(menuAtTheEntreance())
		{
		case 1:
			userData dataOfAccount;

		case 2:

		case 3:{
			return NULL;
		}
		}
		return 0;
	} while (true);
}