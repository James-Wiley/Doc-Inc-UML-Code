#include "AuthService.h"

bool AuthService::authenticate(const std::string& username,
                                    const std::string& password)
{
    // Example business rule
    return username == "admin" && password == "password123";
}