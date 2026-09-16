#include<unihead.hpp>
void processControls(GLFWwindow *win){
    if(glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(win, true);
    }
}
