#ifndef USER_H
#define USER_H

#include <string>

class User {

private:
	std::string userID;
	std::string email;
	std::string phoneNumber;
	std::string role;

public:
	void login();

	void viewStatements();

	void updatePreferences();
};

#endif
