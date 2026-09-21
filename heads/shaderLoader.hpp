#include<unihead.hpp>

class ShaderProgram{
private:
    int shader_program_id{};
    unsigned int ShaderBit(std::string shader_input_name){
        std::string shader_type=shader_input_name.substr((shader_input_name.length()-3),3);
        std::fstream shader_file(("./shader/"+shader_input_name));
        if(!shader_file.is_open()){
            std::cout<<"SHADER FILE NOT OPENED - "+shader_input_name<<std::endl;
            return 0;
        }


        glCreateShader
        glShaderSource
        glCompileShader
    }
public:
    ShaderProgram(std::vector<std::string> shaders_to_program){
        shader_program_id=glCreateProgram();


        glAttachShader
    }



        }

    }

};
