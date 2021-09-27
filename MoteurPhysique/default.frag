#version 330 core
out vec4 FragColor;


in vec3 color;		// Input the color from the vertex Shader

in vec2 texCoord;	// Input the texture coordinate from the vertex Shader

uniform sampler2D tex0;		//gets the texture unit from the main fonction


void main()
{
   FragColor = texture(tex0, texCoord);
}