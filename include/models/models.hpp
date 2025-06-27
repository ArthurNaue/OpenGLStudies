#ifndef MODELS_HPP
#define MODELS_HPP

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>

typedef enum ModelType{CUBE=0} ModelType;

class Model
{
	public:
		Model(ModelType model);

		float* GetVertices(void);
		float GetVerticesSize(void);
	private:
		float* vertices;
		size_t verticesSize;
};

extern float cube[];
extern size_t cubeSize;
extern int cubesNumber;
extern std::vector<glm::vec3> cubePositions;
extern Model cubeModel;

void CreateCube(glm::vec3 pos);

#endif
