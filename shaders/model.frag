#version 130

in	 vec3	f_normal;
in	 vec2	f_texcoord;
in	 vec3 	f_vert;

out	 vec4	out_color;

uniform  vec3      color;
uniform	 sampler2D tex;
uniform	 mat4	   transform;

void main(void)
{
	vec3 light = vec3(25,100,25) - f_vert;
	float intensity = dot(normalize(light), normalize(f_normal));
	intensity = max(0,intensity);


	vec4 c = vec4(color.x,color.y,color.z,1);
	/*if (intensity > 0.5)
		c = vec4(color.x - 0.2, color.y - 0.2, color.z - 0.2,1.0);
	else if (intensity > 0.25)
		c = vec4(color.x - 0.4, color.y - 0.4, color.z - 0.4,1.0);
	else
		c = vec4(color.x - 0.6, color.y - 0.6, color.z - 0.6,1.0);*/
		
	out_color = texture2D(tex,f_texcoord)+c*intensity;
}