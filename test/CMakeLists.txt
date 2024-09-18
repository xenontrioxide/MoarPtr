cmake_minimum_required(VERSION 3.20)
find_package(GTest CONFIG REQUIRED)

include(GoogleTest)

add_executable(MoarPtrTests test_moar_ptr.cpp)

target_link_libraries(MoarPtrTests PRIVATE GTest::gtest GTest::gtest_main MoarPtr)

gtest_discover_tests(MoarPtrTests)