#include "Mesh.h"
#include "VBO.h"
#include "VAO.h"
#include "Shader.h"

Mesh::Mesh()
{
	Vertex vertices_tmp[] =
	{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
		Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
	};

	// Indices for vertices order
	GLuint indices_tmp[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	// Texture data
	Texture textures_tmp[]
	{
		Texture("planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices_tmp, vertices_tmp + sizeof(vertices_tmp) / sizeof(Vertex));
	std::vector <GLuint> ind(indices_tmp, indices_tmp + sizeof(indices_tmp) / sizeof(GLuint));
	std::vector <Texture> tex(textures_tmp, textures_tmp + sizeof(textures_tmp) / sizeof(Texture));


	Mesh::vertices = verts;
	Mesh::indices = ind;
	Mesh::textures = tex;
}

void Mesh::bind()
{


	VAO.bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO(vertices);
	// Generates Element Buffer Object and links it to indices
	EBO EBO(indices);
	// Links VBO attributes such as coordinates and colors to VAO
	VAO.linkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.linkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.linkAttrib(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
	VAO.linkAttrib(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO.unBind();
	VBO.unBind();
	EBO.unBind();



	shaderProgram = new Shader("default.vert", "default.frag");
}


void Mesh::Draw(Camera& camera, float scale)
{
	glm::vec4 lightColor = glm::vec4(1.0f, 0.5f, 0.0f, 1.0f);

	glm::vec3 objectPos = glm::vec3(this->position.x, this->position.y, this->position.z);
	glm::vec3 objectScale = glm::vec3(scale);
	glm::mat4 objectModel = glm::mat4(1.0f);
	objectModel = glm::translate(objectModel, objectPos);
	objectModel = glm::scale(objectModel, objectScale);

	shaderProgram->activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->m_ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(shaderProgram->m_ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);


	// Bind shader to be able to access uniforms
	shaderProgram->activate();
	VAO.bind();

	// Keep track of how many of each type of textures we have
	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string num;
		std::string type = textures[i].m_type;
		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		}
		else if (type == "specular")
		{
			num = std::to_string(numSpecular++);
		}
		textures[i].texUnit(*shaderProgram, (type + num).c_str(), i);
		textures[i].bind();
	}
	// Take care of the camera Matrix
	glUniform3f(glGetUniformLocation(shaderProgram->m_ID, "camPos"), camera.position.x, camera.position.y, camera.position.z);
	camera.Matrix(*shaderProgram, "camMatrix");

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::terminate()
{
	this->shaderProgram->terminate();
}
