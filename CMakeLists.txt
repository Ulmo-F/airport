cmake_minimum_required(VERSION 3.14)
project(airport)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_compile_options(-Wall -Wextra -Werror)  # TODO MSVC...

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
include(GoogleTest)

if(BUILD_TESTING)
    enable_testing()
endif()


add_subdirectory(Geometry)
add_subdirectory(test)

add_executable(airport main.cpp)
target_link_libraries(airport Geometry)
