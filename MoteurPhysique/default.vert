#version 330 core
layout (location = 0) in vec3 aPos;		//Position/Coordinates
layout (location = 1) in vec3 aColor;	//Colors
layout(location = 2) in vec2 aTex;		//Texture


out vec3 color;		// Outputs the color for the Fragment Shader

out vec2 texCoord;	// Outputs the texture coordinate tothe Fragment shader

uniform float scale;	// COntrol the scale of the vertices

uniform mat4 camMatrix;

void main()
{
   gl_Position = camMatrix*vec4(aPos, 1.0f);

   
   color = aColor;		// Assigns the colors				from the Vertex Data to "color"
   texCoord = aTex;		// Assigns the texture coordinate	from the Vertex Data to "texCoord"

}