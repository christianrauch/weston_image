cmake_minimum_required(VERSION 2.8)
project(weston_image)

find_package(PkgConfig)
pkg_check_modules(cairo REQUIRED cairo)
pkg_check_modules(pixman REQUIRED pixman-1)

include_directories(src src/shared src/protocol)

#add_definitions(-Wall -Wextra -Werror)

add_definitions(-DLIBEXECDIR="/usr/lib/weston")
add_definitions(-DDATADIR="/usr/share")

file(GLOB_RECURSE SRC src/*.c)

add_executable(weston_image ${SRC} ${WL_PROT_SRC})
target_include_directories(weston_image PUBLIC ${cairo_INCLUDE_DIRS} ${pixman_INCLUDE_DIRS})

target_link_libraries(weston_image "-lwayland-client;-lpng;-lm")

target_link_libraries(weston_image ${cairo_LIBRARIES} ${pixman_LIBRARIES})
target_link_libraries(weston_image "-lwayland-cursor")
target_link_libraries(weston_image "-lxkbcommon")
target_link_libraries(weston_image "-ljpeg")
target_link_libraries(weston_image "-lwebp")
