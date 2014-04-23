#version 130

in	 vec3	f_normal;
in	 vec2	f_texcoord;

out	 vec4	out_color;

uniform	 sampler2D tex;
uniform	 mat4	   transform;

void main(void)
{
	vec3 light = vec3(0.58,0.58,0.58);

	float intensity = dot(normalize(light), normalize(f_normal));
	intensity = max(0,intensity);

	light *= intensity;

	out_color = texture2D(tex,f_texcoord)*intensity;
}
