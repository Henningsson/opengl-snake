#version 150


in   vec2 f_texcoord;

out  vec4 out_Color;

uniform sampler2D tex;

void main(void)
{
	out_Color = texture(tex,f_texcoord);
}
