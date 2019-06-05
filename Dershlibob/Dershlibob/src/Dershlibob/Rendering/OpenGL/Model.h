#pragma once

#include "assimp\Importer.hpp"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

#include "Shader.h"
#include "Mesh.h"


class Model
{
public:
	Model(char* path)
	{
		loadModel(path);
	}
	void Draw(Shader& shader);

private:

	std::vector<TextureData> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;

	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<TextureData> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char *path, const std::string &directory);

};