cmake_minimum_required(VERSION 3.7)

project(BowlingGame)

enable_testing()
find_package(GTest REQUIRED)

add_executable(BobsBowlingGame test.cpp game.cpp)

target_link_libraries(BobsBowlingGame GTest::GTest GTest::Main)

gtest_add_tests(BobsBowlingGame "" AUTO)
