#version 460 core

layout (location=0) in vec3 form;
layout (location=1) in vec3 normal;
layout (location=2) in vec2 tex_coord;

uniform vec4 color;

out vec4 color_out;
void main(){
    color_out=color;
    gl_Position=vec4(form, 1.0);
}
