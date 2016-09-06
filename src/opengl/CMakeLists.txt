#add_executable(opengl test.exe.cpp)
#add_executable(blender blender.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glew REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
include_directories(${glfw3_INCLUDE_DIRS})

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

#target_link_libraries(opengl ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw3 ${GLEW_LIBRARY})
#target_link_libraries(blender ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw3 ${GLEW_LIBRARY})

link_directories(${GLFW_LIBRARY_DIRS})

add_library(acl_gl ../common/acllib.h acllib.c window.c window.h)
target_link_libraries(acl_gl
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY}
        glfw3
        ${GLEW_LIBRARY}
        ${FREETYPE_LIBRARIES}
        )