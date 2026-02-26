#pragma once
#include <memory>
#include <string>

class AccountRepository
{
public:
    virtual ~AccountRepository() = default;
    virtual double get_balance(const std::string& id) = 0;
    virtual void update_balance(const std::string& id, double amount) = 0;
};

class NotificationService
{
public:
    virtual ~NotificationService() = default;
    virtual void notify(const std::string& message) = 0;
};

class TransferService
{
public:
    TransferService(AccountRepository& repo,
                    NotificationService& notifier);

    bool transfer(const std::string& from,
                  const std::string& to,
                  double amount);

private:
    AccountRepository& repo_;
    NotificationService& notifier_;
};