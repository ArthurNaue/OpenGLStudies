#ifndef MODELS_HPP
#define MODELS_HPP

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader/shader.hpp"
#include "texture/texture.hpp"

typedef enum ModelType{CUBE=0} ModelType;

class Model
{
	public:
		Model(ModelType model, Texture tex, glm::vec3 pos);


		float* GetVertices(void);
		float GetVerticesSize(void);
		glm::vec3 GetPos(void);
		Texture GetTex(void);
	private:
		float* vertices;
		size_t verticesSize;
		Texture tex;
		glm::vec3 pos;
};

extern float cube[];
extern size_t cubeSize;
extern int cubesNumber;
extern std::vector<Model> cubesList;

void DrawCubes(Shader shader);

#endif
