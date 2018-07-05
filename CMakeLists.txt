cmake_minimum_required(VERSION 3.11)
project(xhidecursor)

set(CMAKE_CXX_STANDARD 11)

add_executable(xhidecursor main.cpp)

find_package(X11 REQUIRED)

include_directories(${X11_INCLUDE_DIR})

link_directories(${X11_LIBRARIES})

target_link_libraries(xhidecursor ${X11_LIBRARIES} -lXfixes)

