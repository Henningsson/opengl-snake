#version 130

in	 vec3	f_normal;

out	 vec4	out_color;

uniform	 mat4	transform;

void main(void)
{
	vec3 light = vec3(0.58,0.58,0.58);

	float intensity = dot(normalize(light), normalize(f_normal));
	intensity = max(0,intensity);

	light *= intensity;

	out_color = vec4(intensity);
}
