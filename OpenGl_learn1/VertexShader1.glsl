#version 330 core
layout(location=0) in vec3 position;
layout(location=1) in vec3 color;
out vec3 ourColor;
out vec4 vertexColor;
uniform vec4 translate;

void main()
{
		gl_Position=vec4(position.xyz,1.0f);
		vertexColor=vec4(0.6f,0.2f,0.3,1.0f);
		ourColor=color;
}