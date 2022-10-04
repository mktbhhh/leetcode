cmake_minimum_required(VERSION 3.14)
project(leetcode)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(main main.cpp)
add_executable(leetcode13 leetcode13/main.cpp)
add_executable(leetcode14 leetcode14/main.cpp)
add_executable(leetcode15 leetcode15/main.cpp)
add_executable(leetcode16 leetcode16/main.cpp)
add_executable(leetcode17 leetcode17/main.cpp)
add_executable(leetcode18 leetcode18/main.cpp)

target_link_libraries(leetcode14 GTest::gtest_main)
target_link_libraries(leetcode13 GTest::gtest_main)
target_link_libraries(leetcode15 GTest::gtest_main)
target_link_libraries(leetcode16 GTest::gtest_main)
target_link_libraries(leetcode17 GTest::gtest_main)
target_link_libraries(leetcode18 GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(leetcode14)
gtest_discover_tests(leetcode13)
gtest_discover_tests(leetcode15)
gtest_discover_tests(leetcode16)
gtest_discover_tests(leetcode17)
gtest_discover_tests(leetcode18)
