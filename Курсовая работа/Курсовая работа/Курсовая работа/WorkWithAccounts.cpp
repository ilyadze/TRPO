#include "WorkWithAccounts.h"

struct userData
{
	string login;
	string password;
	string salt;
	bool isAccess = false;
	bool isAdministrator = false;
};

