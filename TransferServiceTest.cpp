#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TransferService.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Exactly;

// STUB (Fake Repository)
class StubAccountRepository : public AccountRepository
{
public:
    double balance_ = 0.0;

    double get_balance(const std::string&) override
    {
        return balance_;
    }

    void update_balance(const std::string&, double amount) override
    {
        balance_ += amount;
    }
};


// MOCK (Notifications)
class MockNotificationService : public NotificationService
{
public:
    MOCK_METHOD(void, notify, (const std::string& message), (override));
};

/* -------------------------
   TEST 1 - Success Case
--------------------------*/
TEST(TransferServiceTest, TransferSucceedsWhenFundsAvailable)
{
    StubAccountRepository repo;
    repo.balance_ = 100.0;

    MockNotificationService notifier;

    EXPECT_CALL(notifier, notify(_)).Times(Exactly(1));

    TransferService service(repo, notifier);

    bool result = service.transfer("A", "B", 50.0);

    EXPECT_TRUE(result);
    EXPECT_EQ(repo.balance_, 100.0); // net zero in stub
}


// TEST 2 - Insufficient Funds
TEST(TransferServiceTest, TransferFailsWhenInsufficientFunds)
{
    StubAccountRepository repo;
    repo.balance_ = 20.0;

    MockNotificationService notifier;

    EXPECT_CALL(notifier, notify(_)).Times(0);

    TransferService service(repo, notifier);

    bool result = service.transfer("A", "B", 50.0);

    EXPECT_FALSE(result);
}

// TEST 3 - Edge Case
TEST(TransferServiceTest, TransferExactBalance)
{
    StubAccountRepository repo;
    repo.balance_ = 50.0;

    MockNotificationService notifier;

    EXPECT_CALL(notifier, notify(_)).Times(1);

    TransferService service(repo, notifier);

    bool result = service.transfer("A", "B", 50.0);

    EXPECT_TRUE(result);
}