#version 130

in      vec3 in_position;
in	vec3 in_normal;
in	vec2 in_texcoord;

out     vec2 f_texcoord;

uniform mat4 projection;
uniform mat4 transform;
uniform mat4 lookat;


void main(void)
{
	gl_Position = projection*vec4(mat3(lookat)*in_position,1.0);
	f_texcoord = in_texcoord;
}