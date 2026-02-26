#include "User.h"
#include <stdexcept>

User::User(const std::string& username,
           AuthService* auth_service)
    : username_(username),
      auth_service_(auth_service)
{
}

bool User::login(const std::string& password)
{
    if (!auth_service_->authenticate(username_, password))
    {
        throw std::runtime_error("Invalid credentials");
    }

    return true;
}