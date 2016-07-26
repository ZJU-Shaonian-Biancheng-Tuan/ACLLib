CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
