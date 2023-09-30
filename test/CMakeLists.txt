add_executable(Geometry_test basic.cpp)

target_link_libraries(Geometry_test   Geometry GTest::gtest_main)

gtest_discover_tests(Geometry_test)
