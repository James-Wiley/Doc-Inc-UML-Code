cmake_minimum_required(VERSION 3.14)
project(DocIncTests)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

find_package(GTest REQUIRED)

add_executable(tests
    TransferService.cpp
    TransferServiceTest.cpp
)

target_link_libraries(tests
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)