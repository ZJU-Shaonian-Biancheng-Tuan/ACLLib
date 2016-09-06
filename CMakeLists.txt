CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(ACLLib)
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Wall -Werror -Wextra")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
