#include "User.h"
#include <stdexcept>

User::User(const std::string& username,
           AuthService* auth_service,
           StatementRepository* statement_repo)
    : username_(username),
      auth_service_(auth_service),
      statement_repo_(statement_repo)
{
}

bool User::login(const std::string& password)
{
    if (!auth_service_)
        throw std::runtime_error("Auth service unavailable");

    if (!auth_service_->authenticate(username_, password))
        throw std::runtime_error("Invalid credentials");

    return true;
}

std::vector<std::string> User::viewStatements()
{
    if (!statement_repo_)
        return {};

    return statement_repo_->getStatementsForUser(username_);
}