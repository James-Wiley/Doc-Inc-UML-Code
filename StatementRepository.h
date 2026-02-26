#ifndef STATEMENTREPOSITORY_H
#define STATEMENTREPOSITORY_H

#include <string>
#include <vector>

class StatementRepository
{
public:
    virtual std::vector<std::string>
    getStatementsForUser(const std::string& username) = 0;

    virtual ~StatementRepository() = default;
};

#endif