#version 130

in	vec3 in_position;
in	vec3 in_normal;
in	vec2 in_texcoord;

out	vec3 f_normal;
out	vec2 f_texcoord;
out	vec3 f_vert;

uniform vec3 color;
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 lookat;

void main()
{
	gl_Position = projection*lookat*transform*vec4(in_position,1.0);

	f_normal   = mat3(lookat*transform)*in_normal;
	f_texcoord = in_texcoord;
	f_vert     = vec3(lookat*transform*vec4(in_position,1.0));
}