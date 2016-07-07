add_executable(main main.c)

include_directories(../src/common)
target_link_libraries(main acllib)