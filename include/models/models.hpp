#ifndef MODELS_HPP
#define MODELS_HPP

#include <cstddef>

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

#endif
