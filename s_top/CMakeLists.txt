cmake_minimum_required(VERSION 2.6)
project(monitor)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(stop ${SOURCES})

set_property(TARGET stop PROPERTY CXX_STANDARD 17)
target_link_libraries(stop ${CURSES_LIBRARIES})
# TODO: Run -Werror in CI.
target_compile_options(stop PRIVATE -Wall -Wextra)
