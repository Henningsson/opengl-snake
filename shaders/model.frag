#version 130

in	 vec3	f_normal;
in	 vec2	f_texcoord;
in	 vec3 	f_vert;

out	 vec4	out_color;

uniform  vec3      color;
uniform	 sampler2D tex;
uniform	 mat4	   transform;
uniform  mat4      lookat;

void main(void)
{
	vec3 light = vec3(25,100,25) - f_vert;

	float intensity = dot(normalize(light), normalize(f_normal));
	intensity = max(0,intensity);

	out_color = texture2D(tex,f_texcoord) + vec4(color,1.0) *intensity;
}