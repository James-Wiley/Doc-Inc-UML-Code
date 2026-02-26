#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <string>

class AuthService
{
public:
    virtual bool authenticate(const std::string& username,
                              const std::string& password) = 0;

    virtual ~AuthService() = default;
};

#endif