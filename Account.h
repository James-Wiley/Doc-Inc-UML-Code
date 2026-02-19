#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

private:
	String accountNumber;
	String accountType;
	String status;

public:
	void validate();

	void linkToUser();
};

#endif
