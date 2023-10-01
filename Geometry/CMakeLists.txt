file(GLOB_RECURSE LIB_SOURCE CONFIGURE_DEPENDS Geometry/*.cpp)
add_library(Geometry SHARED ${LIB_SOURCE})

target_include_directories(Geometry PUBLIC .)

# set_property(TARGET Geometry PROPERTY COMPILE_WARNING_AS_ERROR ON)
# target_compile_options(Geometry PRIVATE
#   $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
#   $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
# )
