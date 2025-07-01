#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
	public:
	    unsigned int ID;

	    Shader(const char* vertexPath, const char* fragmentPath);

	    void Use(void);

	    void SetBool(const std::string &name, bool value);
	    void SetInt(const std::string &name, int value);
	    void SetFloat(const std::string &name, float value);
	    void SetVec2(const std::string &name, const glm::vec2 &value);
	    void SetVec2(const std::string &name, float x, float y);
	    void SetVec3(const std::string &name, const glm::vec3 &value);
	    void SetVec3(const std::string &name, float x, float y, float z);
	    void SetVec4(const std::string &name, const glm::vec4 &value);
	    void SetVec4(const std::string &name, float x, float y, float z, float w);
	    void SetMat2(const std::string &name, const glm::mat2 &mat);
	    void SetMat3(const std::string &name, const glm::mat3 &mat);
	    void SetMat4(const std::string &name, const glm::mat4 &mat);

	private:
	    void CheckCompileErrors(GLuint shader, std::string type);
};

#endif

