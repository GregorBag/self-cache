cmake_minimum_required(VERSION 3.16)
project(lfu_in_cxx LANGUAGES CXX)

add_library(lfu_cache INTERFACE)
target_include_directories(lfu_cache INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(lfu_cache INTERFACE cxx_std_17)

add_executable(lfu cache.cc)
target_link_libraries(lfu PRIVATE lfu_cache)
set_target_properties(lfu PROPERTIES CXX_EXTENSIONS OFF)

# include(CTest)
# if(BUILD_TESTING)
#   add_executable(cache_tests tests/cache_tests.cc)
#   target_link_libraries(cache_tests PRIVATE lfu_cache)
#   add_test(NAME cache COMMAND cache_tests)
#   find_package(Python3 COMPONENTS Interpreter)
#   if(Python3_Interpreter_FOUND)
#     add_test(NAME driver COMMAND "${Python3_EXECUTABLE}"
#       "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_lfu.py" "$<TARGET_FILE:lfu>")
#   endif()
# endif()
