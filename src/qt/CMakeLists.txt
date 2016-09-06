add_library(acl_qt
        ${ACL_HEADERS}
        functionalities/acllib.cpp
        window.cpp window.h
        components/timer.cpp components/timer.h
        components/PaintArea.cpp components/PaintArea.h
        )

set(CMAKE_INCLUDE_CURRENT_DIR OFF)
set(CMAKE_AUTOMOC OFF)

find_package(Qt5Widgets)

target_link_libraries(acl_qt Qt5::Widgets)
set_target_properties(acl_qt PROPERTIES CXX_VERSION 14)