#include "glad/glad.h"
#include<string>
#include<vector>
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/ext.hpp>

class RenderShape {
private:
    GLuint VAO{}, VBO{}, EBO{};
	unsigned int n_verticles{},n_indexes{};

public:
    RenderShape(std::vector<float> &vertex_data, std::vector<unsigned int> &index_data){
		n_verticles=vertex_data.size()/8;
		n_indexes=index_data.size();
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertex_data.size(),vertex_data.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*index_data.size(),index_data.data(),GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)0 );
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)(3*sizeof(float)) );
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE,8*sizeof(float),(void *)(6*sizeof(float)) );

    }
    void render(){
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, n_indexes, GL_UNSIGNED_INT,NULL);
		glBindVertexArray(0);
	}
};

class RenderTexture{



};
