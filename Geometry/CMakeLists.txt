add_library(Geometry SHARED Geometry/Utils.cpp)

target_include_directories(Geometry PUBLIC .)

target_link_libraries(Geometry PUBLIC spdlog::spdlog)

# set_property(TARGET Geometry PROPERTY COMPILE_WARNING_AS_ERROR ON)
# target_compile_options(Geometry PRIVATE
#   $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
#   $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
# )
