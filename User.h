#ifndef USER_H
#define USER_H

class User {

private:
	String userID;
	String email;
	String phoneNumber;
	String role;

public:
	void login();

	void viewStatements();

	void updatePreferences();
};

#endif
