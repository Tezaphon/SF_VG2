cmake_minimum_required(VERSION 4.3.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(SkyFighters LANGUAGES CXX C)
add_executable(SkyFighters
main.cpp controls.cpp glad.c)
target_include_directories(SkyFighters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/heads/)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(SkyFighters glfw OpenGL::GL)



