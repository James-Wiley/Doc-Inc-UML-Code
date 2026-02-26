#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "User.h"

using ::testing::Return;
using ::testing::_;

// MOCK for AuthService
class MockAuthService : public AuthService
{
public:
    MOCK_METHOD(bool, authenticate,
                (const std::string&, const std::string&),
                (override));
};

// STUB for StatementRepository
class StubStatementRepository : public StatementRepository
{
public:
    std::vector<std::string> getStatementsForUser(
        const std::string& username) override
    {
        return {"Invoice1", "Invoice2"};
    }
};

// Normal business logic test
TEST(UserTests, LoginSucceedsWithValidCredentials)
{
    MockAuthService auth;
    EXPECT_CALL(auth, authenticate("james", "password"))
        .WillOnce(Return(true));

    User user("james", &auth, nullptr);

    EXPECT_TRUE(user.login("password"));
}

// Mock-based test (locked user case)
TEST(UserTests, LoginFailsWhenAuthenticationFails)
{
    MockAuthService auth;
    EXPECT_CALL(auth, authenticate(_, _))
        .WillOnce(Return(false));

    User user("james", &auth, nullptr);

    EXPECT_THROW(user.login("wrongpass"), std::runtime_error);
}


// Stub-based test (view statements)
TEST(UserTests, ViewStatementsReturnsUserStatements)
{
    StubStatementRepository repo;

    User user("james", nullptr, &repo);

    auto statements = user.viewStatements();

    EXPECT_EQ(statements.size(), 2);
    EXPECT_EQ(statements[0], "Invoice1");
}