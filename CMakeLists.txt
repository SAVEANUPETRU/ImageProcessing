cmake_minimum_required(VERSION 3.30)
project(Image)

set(CMAKE_CXX_STANDARD 20)

add_executable(Image main.cpp size.cpp image.cpp point.cpp rectangle.cpp draw.cpp imageprocessing.cpp)
