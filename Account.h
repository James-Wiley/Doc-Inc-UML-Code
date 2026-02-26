#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {

private:
	std::string accountNumber;
	std::string accountType;
	std::string status;
	double balance;

public:
	Account(std::string id, double balance);
	void validate();
	void linkToUser();
    double get_balance() const;
    void debit(double amount);
    void credit(double amount);
};

#endif
