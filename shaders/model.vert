#version 130

in	vec3 in_position;
in	vec3 in_normal;
in	vec3 in_texcoord;
uniform mat4 transform;

void main()
{
	gl_Position = vec4(in_position,1.0);
}
