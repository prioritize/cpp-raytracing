project(GoogleTests)
add_subdirectory(include/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(GoogleTests tests.cpp)
target_link_libraries(GoogleTests gtest gtest_main)