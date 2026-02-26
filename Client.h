#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {

private:
	std::string clientID;
	std::string name;

public:
	void manageUsers();
};

#endif
