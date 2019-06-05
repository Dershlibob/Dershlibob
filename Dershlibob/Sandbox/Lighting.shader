#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core 
out vec4 FragColor;

uniform vec3 objectColour;
uniform vec3 lightColour;

void main()
{
	FragColor = vec4(lightColour * objectColour, 1.0);
}