cmake_minimum_required(VERSION 2.8)
project(phys2d)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR} ${phys2d_SOURCE_DIR}/include)

add_executable(phys2d source/main.cpp source/world.cpp source/screen.cpp source/entity.cpp source/grid.cpp)
target_link_libraries(phys2d ${SDL2_LIBRARIES})



install(TARGETS phys2d RUNTIME DESTINATION bin)