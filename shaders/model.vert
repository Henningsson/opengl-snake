
in	vec3 position;
in	vec3 normal;
in 	mat4 transform;

void main()
{
	gl_Position = transform*vec4(position,1.0);
}