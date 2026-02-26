cmake_minimum_required(VERSION 3.20)
project(DocInc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Main project library
add_library(docinc
    User.cpp
    AuthService.cpp
)

target_include_directories(docinc PUBLIC
    ${PROJECT_SOURCE_DIR}
)

# Fetch GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(runTests
    UserTests.cpp
)

target_link_libraries(runTests
    docinc
    gtest_main
    gmock
)

include(GoogleTest)
gtest_discover_tests(runTests)