#version 330 core

out vec4 color;
uniform vec4 ourColor_u;
in vec3 ourColor;
void main()
{
	//color=vec4(0.9f,0.4f,0.5f,1.0f);
	color=vec4(ourColor.r,ourColor.g,ourColor.b,1.0f);
	//color=ourColor_u;
}