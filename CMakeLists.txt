cmake_minimum_required(VERSION 3.10)

project(LearnOpenGL CXX C)

set(CMAKE_CXX_STANDARD 17)

# Diretórios de include
include_directories(include)
include_directories(libraries/glfw/include)
include_directories(libraries/glad/include)

# GLFW como subdiretório (estático, compilado junto)
add_subdirectory(libraries/glfw)

# GLAD como biblioteca estática (mantido separado)
add_library(glad STATIC src/glad/glad.c)
target_include_directories(glad PUBLIC libraries/glad/include)

# Busca automaticamente todos os .cpp e .c da pasta src
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.c)

# Executável principal
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Linkagem
target_link_libraries(${PROJECT_NAME}
    glad
    glfw
    GL
    dl
    m
    X11
    Xrandr
    Xi
    Xxf86vm
    Xinerama
    Xcursor
)

# Copia a pasta assets (shaders, texturas, etc.) para a pasta de build
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
