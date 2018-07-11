cmake_minimum_required(VERSION 2.8)
project(weston_image)

include_directories(src)
include_directories(src/shared)
include_directories(src/protocol)
include_directories(/usr/include/cairo)
include_directories(/usr/include/pixman-1)

# TODO: set correct paths
add_definitions(-DLIBEXECDIR="/usr/lib/weston")
add_definitions(-DDATADIR="/usr/share")

file(GLOB_RECURSE SRC src/*.c)
message(${SRC})

add_executable(weston_image ${SRC} ${WL_PROT_SRC})
target_link_libraries(weston_image "-lwayland-client;-lcairo;-lpixman-1;-lpng;-lm")
target_link_libraries(weston_image "-lwayland-cursor")
target_link_libraries(weston_image "-lxkbcommon")
target_link_libraries(weston_image "-ljpeg")
target_link_libraries(weston_image "-lwebp")
