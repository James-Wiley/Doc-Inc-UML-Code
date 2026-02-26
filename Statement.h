#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>

class Statement {

private:
	std::string statementId;
	Date issueDate;
	std::string deliveryType;
	std::string filePath;

public:
	void generate();

	void access();
};

#endif
