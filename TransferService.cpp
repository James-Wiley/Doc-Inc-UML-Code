#include "TransferService.h"

TransferService::TransferService(AccountRepository& repo,
                                 NotificationService& notifier)
    : repo_(repo), notifier_(notifier)
{
}

bool TransferService::transfer(const std::string& from,
                               const std::string& to,
                               double amount)
{
    if (repo_.get_balance(from) < amount)
    {
        return false;
    }

    repo_.update_balance(from, -amount);
    repo_.update_balance(to, amount);

    notifier_.notify("Transfer successful");

    return true;
}