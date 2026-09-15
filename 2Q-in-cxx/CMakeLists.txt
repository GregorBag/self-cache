cmake_minimum_required(VERSION 3.16)
project(2Q_in_cxx LANGUAGES CXX)

add_library(2Q_cache INTERFACE)
target_include_directories(2Q_cache INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(2Q_cache INTERFACE cxx_std_17)

add_executable(2Q cache.cc)
target_link_libraries(2Q PRIVATE 2Q_cache)
set_target_properties(2Q PROPERTIES CXX_EXTENSIONS OFF)

# include(CTest)
# if(BUILD_TESTING)
#   add_executable(cache_tests tests/cache_tests.cc)
#   target_link_libraries(cache_tests PRIVATE 2Q_cache)
#   add_test(NAME cache COMMAND cache_tests)
#   find_package(Python3 COMPONENTS Interpreter)
#   if(Python3_Interpreter_FOUND)
#     add_test(NAME driver COMMAND "${Python3_EXECUTABLE}"
#       "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_2Q.py" "$<TARGET_FILE:2Q>")
#   endif()
# endif()
