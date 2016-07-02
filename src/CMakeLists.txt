IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # Linux specific code
    SET(OperatingSystem "Linux")


    FIND_PACKAGE(PkgConfig REQUIRED)
    PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)


    INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
    LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})


    ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")






add_library(acl_gtk common/acllib.h gtk/acllib.c)
add_library(acl_win32 common/acllib.h win32/acllib.c)

TARGET_LINK_LIBRARIES(acl_gtk ${GTK3_LIBRARIES})
