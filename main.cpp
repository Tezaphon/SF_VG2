#include<string>
#include<vector>
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/ext.hpp>

#include<default_cube.hpp>
#include<shader_loader.hpp>
#include<buffers_generator.hpp>

#include<controls.hpp>

void viewportResize(GLFWwindow* win, int w, int h){
    glViewport(0,0, w, h);
}
// void processControls(GLFWwindow *win);
int main(){
    std::cout<<"Hello World! Lets begin!"<<std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
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

    //TEST SCENE
    std::vector<std::string> test_shader_list{"testing.vsh", "testing.fsh"};
    ShaderProgram test_shader(test_shader_list);

    RenderShape cube(default_cube_verticles, default_cube_indexes);
    //TEST SCENE

    while(!glfwWindowShouldClose(window)){
        processControls(window);
        float time_since_start = glfwGetTime();

        glClearColor(1.0f*(cos(time_since_start)+1)/2, 1.0f*(cos(time_since_start+0.5)+1)/2, 1.0f*(cos(time_since_start+1)+1)/2, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //TEST SCENE
        test_shader.use();
        glm::vec4 cube_color{0.4,0.9,0.4,1.0};
        test_shader.setUniform("color",&cube_color);
        cube.render();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
