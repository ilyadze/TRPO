#pragma once
#include "validation.h"


struct userData
{
	string login;
	string password;
	string salt;
	bool isAccess = false;
	bool isAdministrator = false;
};
