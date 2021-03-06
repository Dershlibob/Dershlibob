#pragma once

#include <string>
#include <unordered_map>

#include "glm.hpp"

#include "Dershlibob\core.h"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class DERSHLIBOB_API Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();
	unsigned int GetRendererID();
	void Bind() const;
	void Unbind() const;
	
	// Set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1f(const std::string & name, float v0);
	void SetUniform3f(const std::string & name, float v0, float v1, float v2);
	void SetUniformMat4f(const std::string& name, const glm::mat4& Matrix);

	//static Shader* getInstance(const std::string & filepath);

private:
	ShaderProgramSource ParseShader(const std::string& filePath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);

	//static Shader* instance;
};