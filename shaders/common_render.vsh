#version 460 compatibility

layout (location = 0) in vec3 verticle_shape_postion;
layout (location = 1) in vec3 verticle_normal;
layout (location = 2) in vec2 vertcile_texture_coord;

uniform mat4 world_postion;
uniform mat4 camera_angle_position;
uniform mat4 camera_clip;

uniform mat4 animation;

out vec3 verticle_normal_to_fragment;
out vec3 verticle_texture_coord_to_fragment;

void main(){
	vec4 after_animation=(verticle_shape_postion, 1.0)*animation;
	vec4 after_world_position=after_animation*world_postion;
	vec4 after_camera_angle=after_world_position*camera_angle_position;
	vec4 after_clip=after_camera_angle*camera_clip;
	gl_Position(after_clip);
	verticle_normal_to_fragment=verticle_normal;
	verticle_texture_coord_to_fragment=vertcile_texture_coord;
}
