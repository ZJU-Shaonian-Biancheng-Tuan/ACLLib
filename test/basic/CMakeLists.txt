include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../../src)

add_executable(basicTestRunner basic.cpp)
target_link_libraries(basicTestRunner gtest gtest_main)