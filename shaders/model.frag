#version 130

in	 vec3	f_normal;
in	 vec2	f_texcoord;

out	 vec4	out_color;

uniform	 sampler2D tex;
uniform	 mat4	   transform;

void main(void)
{
	vec3 light = vec3(25.0, 100.0 ,25.0);
	float intensity = dot(normalize(light), normalize(f_normal));
	intensity = max(0,intensity);


	vec4 color;
	if (intensity > 0.95)
		color = vec4(1.0,0.5,0.5,1.0);
	else if (intensity > 0.5)
		color = vec4(0.6,0.3,0.3,1.0);
	else if (intensity > 0.25)
		color = vec4(0.4,0.2,0.2,1.0);
	else
		color = vec4(0.2,0.1,0.1,1.0);
		
	out_color = texture2D(tex,f_texcoord)+color*intensity;
}