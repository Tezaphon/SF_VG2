#include<unihead.hpp>

class ShaderProgram{
private:
    int shader_program_id{};
    unsigned int ShaderObject(std::string shader_input_name){
        std::string shader_type=shader_input_name.substr((shader_input_name.length()-3),3);
        std::fstream shader_file(("./shader/"+shader_input_name));
        if(!shader_file.is_open()){
            std::cout<<"SHADER FILE NOT OPENED - "+shader_input_name<<std::endl;
            return 0;
        }
        std::string shader_code_text{};
        shader_file.read(shader_code_text.data(),shader_file.seekg(0,std::fstream::end).tellg());
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
        const GLchar *shader_code_source=shader_code_text.c_str();
        glShaderSource(shader_object_id,1,&shader_code_source,0);
        glCompileShader(shader_object_id);
        glGetShaderiv()
        glGetShaderInfoLog()
    }
public:
    ShaderProgram(std::vector<std::string> shaders_to_program){
        shader_program_id=glCreateProgram();


        glAttachShader
    }



        }

    }

};
