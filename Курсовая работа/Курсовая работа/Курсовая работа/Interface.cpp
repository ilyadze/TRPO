#include "Interface.h"

int menuAtTheEntreance()
{
	std::cout << "\n1.Autorization"
		<< "\n2.Registration"
		<< "\n3.Exit";
	return inputNumber(3);
}


string loginMenu(string& login)
{
	cout << "Enter login" << endl;
	cin >> login;
	cout << "Enter password" << endl;
	string password;
	password = inputPassword();
	return password;
}
