#pragma once
#include <iostream>
#include <vector>

#include "glm.hpp"

#include"Shader.h"

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};

struct TextureData {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh {
public:
	/*  Mesh Data  */
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<TextureData> textures;
	/*  Functions  */
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<TextureData> textures);
	void Draw(Shader& shader);
private:
	/*  Render data  */
	unsigned int VAO, VBO, EBO;
	/*  Functions    */
	void setupMesh();
};