add_executable(main main.c)

include_directories(../src/common)
target_link_libraries(main acllib)

add_executable(main_gl main.c)
target_link_libraries(main_gl acl_gl)

add_executable(main_qt main.c)
target_link_libraries(main_qt acl_qt)

add_executable(main_win32 main.c)
target_link_libraries(main_win32 acl_win32)

add_executable(main_gtk main.c)
target_link_libraries(main_gtk acl_gtk)

add_executable(mouse_click_qt mouse_click.c)
target_link_libraries(mouse_click_qt acl_qt)

add_executable(mouse_click_win32 mouse_click.c)
target_link_libraries(mouse_click_win32 acl_win32)

add_executable(clock_gl clock.c)
target_link_libraries(clock_gl acl_gl)

add_executable(clock_win32 clock.c)
target_link_libraries(clock_win32 acl_win32)

add_executable(clock_qt clock.c)
target_link_libraries(clock_qt acl_qt)

add_executable(keyboard_win32 keyboard.c)
target_link_libraries(keyboard_win32 acl_win32)

add_executable(keyboard_qt keyboard.c)
target_link_libraries(keyboard_qt acl_qt)