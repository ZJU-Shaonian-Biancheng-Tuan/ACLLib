

add_library(acl_sdl acllib.c SDL2_gfx/SDL2_gfxPrimitives.h functionalities/paint.c functionalities/events.c)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_subdirectory(SDL2_gfx)
target_link_libraries(acl_sdl ${SDL2_LIBRARIES} SDL2_gfx)
set_target_properties(acl_sdl PROPERTIES C_STANDARD 99)
