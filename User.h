#ifndef USER_H
#define USER_H

#include <string>
#include "AuthService.h"

class User
{
public:
    User(const std::string& username,
         AuthService* auth_service);

    bool login(const std::string& password);

private:
    std::string username_;
    AuthService* auth_service_;
};

#endif