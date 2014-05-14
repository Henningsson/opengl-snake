#version 150

in      vec3 in_position;
in	vec2 in_texcoord;

out     vec2 f_texcoord;

uniform mat4 projection;
uniform mat4 transform;
uniform mat4 lookat;


void main(void)
{
	gl_Position = projection*lookat*transform*vec4(in_position,1.0);
	f_texcoord = in_texcoord;
}
