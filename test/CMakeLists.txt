file(GLOB_RECURSE LIB_SOURCE CONFIGURE_DEPENDS *.test.cpp)
add_executable(Geometry_test ${LIB_SOURCE})

target_link_libraries(Geometry_test   Geometry GTest::gtest_main)

gtest_discover_tests(Geometry_test)
