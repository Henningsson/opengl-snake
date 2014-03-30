out	vec4 color;
in	vec2 texcoord;
in	vec3 normal;
uniform sampler2d texture;

void main(void)
{
	color = texture(tex,texcoord);
}
