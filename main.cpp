#include<unihead.hpp>


#include<defaultCube.hpp>
#include<shaderLoader.hpp>

void viewportResize(GLFWwindow* win, int w, int h){
    glViewport(0,0, w, h);
}
void processControls(GLFWwindow *win);
int main(){
    std::cout<<"Hello World! Lets begin!"<<std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window =glfwCreateWindow(1600, 900, "Main Window", NULL, NULL);
    glfwMakeContextCurrent(window);
    if(!window){
        std::cout<<"Main Window = ERROR"<<std::endl;
        glfwTerminate();
        return 1;
    }


    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"GLAD LOADING = ERROR";
        return 1;
    }

    glViewport(0, 0, 1600, 900);
    glfwSetFramebufferSizeCallback(window, viewportResize);

    while(!glfwWindowShouldClose(window)){
        processControls(window);
        float time_since_start = glfwGetTime();

        glClearColor(1.0f*(cos(time_since_start)+1)/2, 1.0f*(cos(time_since_start+0.5)+1)/2, 1.0f*(cos(time_since_start+1)+1)/2, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
