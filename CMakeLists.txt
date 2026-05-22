cmake_minimum_required(VERSION 3.10.0)
project(Minecraft VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)

file(GLOB src src/*.cpp)
file(GLOB imgui dependencies/lib/imgui/*.cpp)

add_executable(Minecraft)

target_sources(Minecraft PRIVATE ${imgui} dependencies/lib/glad.c ${src})

target_include_directories(Minecraft PRIVATE dependencies/includes)
target_include_directories(Minecraft PRIVATE src/includes)

target_link_libraries(Minecraft PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/lib/libglfw3.a"
    OpenGL::GL
)
