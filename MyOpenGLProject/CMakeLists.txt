cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/external/glad/include
    ${PROJECT_SOURCE_DIR}/external/glfw/include
)

# GLAD 靜態庫
add_library(glad STATIC
    ${PROJECT_SOURCE_DIR}/external/glad/src/glad.c
)

# GLFW Import Library (MinGW DLL)
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
    IMPORTED_LOCATION
      ${PROJECT_SOURCE_DIR}/external/glfw/lib/libglfw3dll.a
)

# 主程式
add_executable(main
    src/main.cpp
)

target_link_libraries(main
    glad
    glfw
    opengl32  # Windows 系統 OpenGL
    gdi32     # Windows GDI
)