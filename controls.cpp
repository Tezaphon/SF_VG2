#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/ext.hpp>
void processControls(GLFWwindow *win){
    if(glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(win, true);
    }
}
