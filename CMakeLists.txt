cmake_minimum_required(VERSION 3.16)

project(opengl-graphics)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GL REQUIRED IMPORTED_TARGET gl)
pkg_check_modules(GLFW3 REQUIRED IMPORTED_TARGET glfw3)
pkg_check_modules(GLEW REQUIRED IMPORTED_TARGET glew)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

file(GLOB src_files "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB header_files "${CMAKE_SOURCE_DIR}/include/*.hpp")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(app ${src_files} ${header_files})

target_link_libraries(app
    PUBLIC PkgConfig::GL
    PUBLIC PkgConfig::GLEW
    PUBLIC PkgConfig::GLFW3)