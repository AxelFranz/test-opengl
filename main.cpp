#include <cstdio>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
using namespace glm;


int main(int argc, char** argv) {

    std::cout << "Initializing GLFW : " << std::endl;
    glewExperimental = true;
    if(!glfwInit()) {
        fprintf(stderr,"Failed to initialize GLFW");
        return 1;
    }
    printf("GLFW initialized ! \nConfiguring GLEW...\n");

    // AntiAliasing
    glfwWindowHint(GLFW_SAMPLES, 4);
    // Version 3.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // Core profile : Tout ce qui est utilisable et pas obsolète
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    std::cout << "Opening GLFW window..." << std::endl;
    window = glfwCreateWindow(1025,768,"AAAAAAAAA",NULL,NULL);
    if(window == NULL) {
        std::cerr << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        return 1;
    }
    std::cout << "Window opened !\n Initializing GLEW..." << std::endl;
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return 1;
    }
    std::cout << "GLEW initialized !" << std::endl;

    // Pour assurer le traitement des touches
    glfwSetInputMode(window,GLFW_STICKY_KEYS,GL_TRUE);

    do {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window,GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    
    return 0;
}
