#version 130

in	vec3 in_position;
in	vec3 in_normal;
in	vec3 in_texcoord;

out	vec3 f_normal;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 lookat;

void main()
{
	gl_Position = projection*lookat*transform*vec4(in_position,1.0);

	f_normal = mat3(transform)*in_normal;
}
