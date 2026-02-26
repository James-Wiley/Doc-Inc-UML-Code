#include "User.h"

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
        return false;

    return auth_service_->authenticate(username_, password);
}

std::vector<std::string> User::viewStatements()
{
    if (!statement_repo_)
        return {};

    return statement_repo_->getStatementsForUser(username_);
}