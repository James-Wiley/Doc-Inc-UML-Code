#ifndef STATEMENT_H
#define STATEMENT_H

class Statement {

private:
	String statementId;
	Date issueDate;
	String deliveryType;
	String filePath;

public:
	void generate();

	void access();
};

#endif
