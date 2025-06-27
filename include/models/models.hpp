#ifndef MODELS_HPP
#define MODELS_HPP

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>

typedef enum ModelType{CUBE=0} ModelType;

class Model
{
	public:
		Model(ModelType model, glm::vec3 pos);


		float* GetVertices(void);
		float GetVerticesSize(void);
		glm::vec3 GetPos(void);
	private:
		float* vertices;
		size_t verticesSize;
		glm::vec3 pos;
};

extern float cube[];
extern size_t cubeSize;
extern int cubesNumber;
extern std::vector<Model> cubesList;

#endif
