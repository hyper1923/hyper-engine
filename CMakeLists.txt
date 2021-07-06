cmake_minimum_required(VERSION 2.8)

project(HyperEngine)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(IMGUI_SOURCE ${PROJECT_INCLUDE_DIR}/imgui)

file(GLOB IMGUI_SOURCES ${IMGUI_SOURCE}/*.cpp)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

set(PROJECT_SOURCES
            ${PROJECT_SOURCE_DIR}/sandbox/main.cpp
            ${PROJECT_SOURCE_DIR}/glad/glad.c
            ${PROJECT_SOURCE_DIR}/engine/Window.cpp
            ${PROJECT_SOURCE_DIR}/engine/Application.cpp
            ${IMGUI_SOURCES}
            )

set(PROJECT_HEADERS
${PROJECT_SOURCE_DIR}/engine/Window.h
${PROJECT_SOURCE_DIR}/engine/Vertex.h
${PROJECT_SOURCE_DIR}/engine/Entity2D.h
${PROJECT_SOURCE_DIR}/engine/Application.h
${PROJECT_SOURCE_DIR}/engine/Vector2.h
${PROJECT_SOURCE_DIR}/engine/Stats.h
${PROJECT_SOURCE_DIR}/HyperEngine.hpp


)


find_package(glfw3 3.3.2 REQUIRED)



include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})


target_link_libraries(${PROJECT_NAME} glfw)