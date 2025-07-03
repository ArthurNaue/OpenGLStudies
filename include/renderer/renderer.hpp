#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <map>
#include <vector>
#include "models/models.hpp"
#include "shader/shader.hpp"

struct ModelData
{
	unsigned int VAO;
	unsigned int VBO;
	float* vertices;
	size_t vertexSize;
	int vertexCount;
	std::vector<Model> instances;
};

class Renderer
{
	public:
		std::map<ModelType, ModelData> modelDataMap;

		Renderer(void);

		void RegisterModel(ModelType model, float* vertices, size_t size, int count);
		void AddInstance(Model model);
		void DrawAll(Shader& shader);
		void Delete(void);
};

#endif
