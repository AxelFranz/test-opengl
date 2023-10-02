cmake_minimum_required(VERSION 3.12)

project(OpenGLDemo)

# Recherchez le package GLFW
find_package(glfw3 REQUIRED)

# Spécifiez la version de C++ que vous souhaitez utiliser (par exemple, C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajoutez le répertoire d'en-têtes d'OpenGL
find_package(OpenGL REQUIRED)

# Ajoutez le répertoire d'en-têtes de GLEW
find_package(GLEW REQUIRED)

# Créez une cible exécutable pour votre application
add_executable(OpenGLDemo main.cpp)

# Liez les bibliothèques GLFW, OpenGL, GLEW et autres si nécessaire
target_link_libraries(OpenGLDemo glfw OpenGL::GL GLEW::GLEW)

