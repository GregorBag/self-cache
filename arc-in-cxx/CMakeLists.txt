cmake_minimum_required(VERSION 3.16)
project(arc_in_cxx LANGUAGES CXX)

add_library(arc_cache INTERFACE)
target_include_directories(arc_cache INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(arc_cache INTERFACE cxx_std_17)

add_executable(arc cache.cc)
target_link_libraries(arc PRIVATE arc_cache)
set_target_properties(arc PROPERTIES CXX_EXTENSIONS OFF)

# include(CTest)
# if(BUILD_TESTING)
#   add_executable(cache_tests tests/cache_tests.cc)
#   target_link_libraries(cache_tests PRIVATE arc_cache)
#   add_test(NAME cache COMMAND cache_tests)
#   find_package(Python3 COMPONENTS Interpreter)
#   if(Python3_Interpreter_FOUND)
#     add_test(NAME driver COMMAND "${Python3_EXECUTABLE}"
#       "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_arc.py" "$<TARGET_FILE:arc>")
#   endif()
# endif()
