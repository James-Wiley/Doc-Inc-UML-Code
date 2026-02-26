#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <string>

class AuthService
{
public:
    bool authenticate(const std::string& username,
                      const std::string& password);
};

#endif