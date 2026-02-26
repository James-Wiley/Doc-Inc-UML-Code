#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "AuthService.h"
#include "StatementRepository.h"

class User
{
public:
    User(const std::string& username,
         AuthService* auth_service,
         StatementRepository* statement_repo);

    bool login(const std::string& password);
    std::vector<std::string> viewStatements();

private:
    std::string username_;
    AuthService* auth_service_;
    StatementRepository* statement_repo_;
};

#endif