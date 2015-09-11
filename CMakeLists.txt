cmake_minimum_required(VERSION 2.6)
project(phys2d)

add_executable(phys2d main.cpp)

install(TARGETS phys2d RUNTIME DESTINATION bin)
