#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/ext.hpp>

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"


class ShaderProgram{
private:
    GLuint shader_program_id{};
    unsigned int shaderObjectCompile(std::string shader_input_name){
        std::string shader_type=shader_input_name.substr((shader_input_name.length()-3),3);
        std::fstream shader_file(("../shaders/"+shader_input_name));
        if(!shader_file.is_open()){
            std::cout<<"SHADER FILE NOT OPENED - "+shader_input_name<<std::endl;
            return 0;
        }
        std::string shader_code_text{};

        // shader_file.seekg(0,std::fstream::end);
        // int shader_file_length=shader_file.tellg();
        // shader_file.seekg(0, std::fstream::beg);
        // std::cout<<"shader file text - length - "<<shader_file_length<<std::endl;
        // shader_file.read(shader_code_text.data(),shader_file_length);

        getline(shader_file,shader_code_text, '\0');

        unsigned int shader_object_id{};
        if(shader_type=="vsh"){
            shader_object_id=glCreateShader(GL_VERTEX_SHADER);
        }else
        if(shader_type=="fsh"){
            shader_object_id=glCreateShader(GL_FRAGMENT_SHADER);
        }else{
            std::cout<<"UNKNOWN SHADER TYPE - "+shader_input_name<<std::endl;
            return 0;
        }

        std::cout<<"shader file content - "<<shader_code_text<<std::endl;

        std::cout<<"shader - "+shader_input_name+" - file read"<<std::endl;

        const GLchar *shader_code_source=shader_code_text.c_str();
        glShaderSource(shader_object_id,1,&shader_code_source,0);
        glCompileShader(shader_object_id);

        std::cout<<"shader - "+shader_input_name+" - file compiled"<<std::endl;

        int compilation_success{};
        glGetShaderiv(shader_object_id, GL_COMPILE_STATUS,&compilation_success);

        std::cout<<"shader - "+shader_input_name+" - status retireved"<<std::endl;

        if(!compilation_success){
            std::cout<<"shader - "+shader_input_name<<" - compile unsuccesfull"<<std::endl;

            GLint compilation_log_size{0};
            glGetShaderiv(shader_object_id,GL_INFO_LOG_LENGTH,&compilation_log_size);

            std::cout<<"shader - "+shader_input_name<<" - compile unsuccesfull - log length retrieved"<<std::endl;

            char compilation_log[compilation_log_size]{};


            glGetShaderInfoLog(shader_object_id,compilation_log_size,NULL,compilation_log);
            std::cout<<"SHADER - "+shader_input_name+" - compilation log retrieve"<<std::endl;
            std::cout<<"SHADER - "+shader_input_name+" - "+compilation_log<<std::endl;
            glDeleteShader(shader_object_id);
            return 0;
        }

        //std::cout<<"shader - "+shader_input_name+" - DONE"<<std::endl;

        return shader_object_id;
    }
public:
    ShaderProgram(std::vector<std::string> shaders_to_program){
        shader_program_id=glCreateProgram();
        std::vector<GLuint> shader_objects{};
        std::cout<<"proceed with shader program creation"<<std::endl;
        for(std::vector<std::string>::iterator it=shaders_to_program.begin(); it!=shaders_to_program.end();it++){
            shader_objects.push_back(shaderObjectCompile(*it));
            std::cout<<"buzy with - "<<*it<<std::endl;
        }
        std::cout<<"shader object compile for loop done"<<std::endl;
        for(std::vector<GLuint>::iterator it=shader_objects.begin(); it!=shader_objects.end();it++){
            glAttachShader(shader_program_id, *it);
        }
        glLinkProgram(shader_program_id);
        int linking_success{};
        glGetProgramiv(shader_program_id, GL_LINK_STATUS,&linking_success);
        if(!linking_success){
            std::string linking_log{};
            GLint linking_log_size{};
            glGetProgramiv(shader_program_id, GL_INFO_LOG_LENGTH,&linking_log_size);
            glGetProgramInfoLog(shader_program_id,linking_log_size,NULL,linking_log.data());
            std::cout<<"SHADER PROGRAM - "+linking_log<<std::endl;
            glDeleteProgram(shader_program_id);
        }
        for(std::vector<GLuint>::iterator it=shader_objects.begin();it!=shader_objects.end();it++){
            glDetachShader(shader_program_id, *it);
            glDeleteShader(*it);
        }
    }
    void use(){
        glUseProgram(shader_program_id);
    }
    void setUniform(std::string uniform_to_set, glm::mat4 *uniform_data){
        GLint uniform_adress{};
        glGetUniformLocation(shader_program_id, uniform_to_set.c_str());
        if(!uniform_adress){
            std::cout<<"uniform - "<<uniform_to_set<<" - not found"<<std::endl;
        }
        else{
        glUniformMatrix4fv(uniform_adress,1,GL_FALSE,glm::value_ptr(*uniform_data));
        }
    }
    void setUniform(std::string uniform_to_set, glm::vec3 *uniform_data){
        GLint uniform_adress{};
        glGetUniformLocation(shader_program_id,uniform_to_set.c_str());
        if(!uniform_adress){
            std::cout<<"uniform - "<<uniform_to_set<<" - not found"<<std::endl;
        }
        else{
            glUniform3fv(uniform_adress,1,glm::value_ptr(*uniform_data));
        }
    }
    void setUniform(std::string uniform_to_set,glm::vec4 *unifrom_data){
        GLint uniform_adress{};
        glGetUniformLocation(shader_program_id,uniform_to_set.c_str());
        // if(!uniform_adress){
        //     std::cout<<"uniform - "<<uniform_to_set<<" - not found"<<std::endl;
        // }
        // else{
            glUniform4fv(uniform_adress,1,glm::value_ptr(*unifrom_data));
        // }
    }
};
